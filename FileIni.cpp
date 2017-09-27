#include "FileIni.h"
#include <regex>

#define ERROR_MODEL(MODEL) \
if(MODEL) \
{ \
	return ""; \
}

std::string parse(const std::string& text, section_map& secMap)
{
#define NORMAL_MODEL 0
#define SECTION_MODEL 1
#define PROPERTY_MODEL 2
#define ALLINPUT_MODEL 3

	std::string buf;
	buf.reserve(1024);

	std::string section, key, value;
	property_map propertyMap;
	int model1 = NORMAL_MODEL, model2 = NORMAL_MODEL;
	char pattern = '\0';
	for (auto iter = text.begin(); iter != text.end(); ++iter)
	{
		char ch = *iter;
		switch (ch)
		{
		case '[':
			ERROR_MODEL(model1 != NORMAL_MODEL && model2 == PROPERTY_MODEL);
			if (!section.empty())
				secMap.insert(section_map::value_type(section, propertyMap));
			model1 = SECTION_MODEL;
			section.clear();
			break;
		case ']':
			ERROR_MODEL(model1 != SECTION_MODEL);

			model1 = NORMAL_MODEL;
			section = buf;
			propertyMap = property_map();
			buf.clear();
			break;
		case '\r':
		case '\n':
			ERROR_MODEL(model1 != NORMAL_MODEL);
			if (model2 != PROPERTY_MODEL)
				break;
			value = buf;
			buf.clear();
			propertyMap.insert(property_map::value_type(key, value));
			key.clear();
			value.clear();
			model2 = NORMAL_MODEL;
			break;
		case ' ':
		case '\t':
			ERROR_MODEL(model1 != NORMAL_MODEL);
			if (model2 == PROPERTY_MODEL)
			{
				if (pattern != 0)
					buf += ch;
				break;
			}else if(buf.empty())
				break;
			model2 = PROPERTY_MODEL;
			key = buf;
			buf.clear();
			break;
		case '\'':
		case '"':
			ERROR_MODEL(model2 != PROPERTY_MODEL);
			if (pattern == 0)
				pattern = ch;
			else if (pattern == ch)
			{
				pattern = 0;
				value = buf;
				buf.clear();
				propertyMap.insert(property_map::value_type(key, value));
			}
			else
				buf += ch;
			break;
		default:
			buf += ch;
		}
	}

	if (!section.empty())
		secMap.insert(section_map::value_type(section, propertyMap));

	return "";
}

FileIni::FileIni(const std::string& path)
	:m_sectionProperty(NULL)
{
	char text[4096] = {};
	::GetModuleFileNameA(NULL, text, sizeof(text));
	m_path = text;
	while (m_path.back() != '\\')
		m_path.pop_back();
	m_path += path;
}

bool FileIni::read()
{
	FILE* f = NULL;
	if (fopen_s(&f, m_path.c_str(), "rb+") != 0)
		return false;
	std::string data;
	fseek(f, 0, SEEK_END);
	data.reserve(ftell(f));
	rewind(f);
	char text[4096] = {};
	while (fread_s(text, sizeof(text), 1, sizeof(text) - 1, f))
	{
		data += text;
	}
	fclose(f);
	auto err = parse(data, m_sectionMap);
	if (!err.empty())
	{
		printf(err.c_str());
		return false;
	}
	return true;
}

void FileIni::write()
{
	if (m_path.empty())
		return;
	FILE* f = NULL;
	if(fopen_s(&f, m_path.c_str(), "wb+") != 0)
		return;
	for (auto secIter = m_sectionMap.begin(); secIter != m_sectionMap.end(); ++secIter)
	{
		std::string key = "[";
		key += secIter->first + "]\r\n";
		property_map& propertyMap = secIter->second;
		fwrite(key.c_str(), 1, key.size(), f);
		for (auto ppIter = propertyMap.begin(); ppIter != propertyMap.end(); ++ppIter)
		{
			std::string val = ppIter->first + "\t" + ppIter->second + "\r\n";
			fwrite(val.c_str(), 1, val.size(), f);
		}
		fwrite("\r\n", 1, 2, f);
	}
	fclose(f);
}

void FileIni::create()
{
	FILE* f = NULL;
	if (fopen_s(&f, m_path.c_str(), "wb+") != 0)
		return;
	fclose(f);
}

bool FileIni::enterSection(const std::string& section)
{
	if (m_sectionMap.find(section) == m_sectionMap.end())
		return false;
	m_sectionProperty = &m_sectionMap.at(section);
	return true;
}

void FileIni::initSection(const std::string& section)
{
	if (m_sectionMap.find(section) == m_sectionMap.end())
		m_sectionMap.insert(section_map::value_type(section, property_map()));
}

std::string FileIni::getValue(const std::string& key) const
{
	if (m_sectionProperty == NULL)
		return "";
	property_map::iterator iter;
	if ((iter = m_sectionProperty->find(key)) == m_sectionProperty->end())
		return "";
	return iter->second;
}

void FileIni::setValue(const std::string& key, const std::string& value)
{
	if (m_sectionProperty == NULL)
		return;
	(*m_sectionProperty)[key] = value;
}

property_map::iterator FileIni::begin()
{
	return m_sectionProperty->begin();
}

property_map::iterator FileIni::end()
{
	return m_sectionProperty->end();
}
