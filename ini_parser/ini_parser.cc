#include "ini_parser.h"
#include "tokener.h"
namespace qh
{
	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator , const std::string& key_value_seperator )
	{
		std::string str(ini_data);
		std::string key_,val_;
		Tokener token(str);
		char* char_key_value_seperator = new char[10];
		char* char_line_seperator = new char[10];
		strcpy(char_key_value_seperator,key_value_seperator.c_str());
		strcpy(char_line_seperator,line_seperator.c_str());
		while (!token.isEnd()) {
			key_=token.nextString(*char_key_value_seperator);
			for(std::string::iterator iter=key_.begin();iter!=key_.end();)
			{
				if(*iter==*char_line_seperator){
					iter = key_.erase(iter);
				}
				else
					iter++;
			}
			val_=token.nextString(*char_line_seperator);
			const char* curpos = token.getCurReadPos();
			int nreadable = token.getReadableSize();


			if (val_.empty() && nreadable > 0) {
                    assert(curpos);
                    val_.assign(curpos, nreadable);
					size_t movetimes =nreadable;
					while(movetimes--)
						token.next();
                }
			key_map.insert(make_pair(key_,val_));
		}
		delete[] char_key_value_seperator;
		delete[] char_line_seperator;
		return 1;
	}
	const std::string& INIParser::Get(const std::string& key, bool* found)
	{
		std::string value;
		if(key_map.count(key))
		{
			value = key_map[key].c_str();
		}
		else
		{
			value = "";

		}
		std::string * pValue = new std::string(value);
		return *pValue;
	}
};