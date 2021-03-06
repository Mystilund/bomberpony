//
// File.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 11 16:25:00 2013 florian dewulf
// Last update Sun May 26 02:02:18 2013 florian dewulf
//

#include	"File.hpp"

File::File() : _map(false)
{
  if (access("./map/", R_OK | F_OK) != -1)
    this->_map = true;
}

File::~File()
{
}

std::list<std::string>	File::ls()
{
  DIR				*dir;
  struct dirent			*st;
  std::list<std::string>	list;

  if (this->_map)
    {
      dir = opendir("./map/");
      if (dir == NULL)
	return list;
      while ((st = readdir(dir)))
	{
	  std::string	str(st->d_name);
	  if (str[0] != '.' && str[str.size() - 1] != '~')
	    list.push_back(str);
	}
      closedir(dir);
    }
  return (list);
}

bool		File::getStatemap() const
{
  return (this->_map);
}

std::list<std::string>	File::getFileContent(const std::string &filename) const
{
  std::ifstream		file(filename.c_str());
  std::string		str;
  std::list<std::string>	list;

  if (file.is_open())
    {
      while (file.good())
	{
	  getline(file, str);
	  if (str != "")
	    list.push_back(str);
	}
      file.close();
    }
  return list;
}

void		File::putFile(const std::string &str, const std::list<std::string> &list)
{
  std::ofstream	out(str.c_str());

  if (out.is_open())
    {
      for (std::list<std::string>::const_iterator it = list.begin() ; it != list.end() ; ++it)
	out << *it << std::endl;
      out.close();
    }
}
