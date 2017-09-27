#ifndef __FILEINI_H__
#define __FILEINI_H__
#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::unordered_map<std::string, std::string> property_map;
typedef std::unordered_map<std::string, property_map> section_map;

class FileIni
{
public:
	FileIni(const std::string& path);
	bool read();
	void write();
	void create();

	std::string getValue(const std::string& key) const;

	bool enterSection(const std::string& section);
	void initSection(const std::string& section);

	void setValue(const std::string& key, const std::string& value);

	property_map::iterator begin();
	property_map::iterator end();
private:
	std::string	m_path;				//配置文件路径
	section_map m_sectionMap;		//配置属性表
	property_map* m_sectionProperty;
};
#endif
