#include<iostream>
#include<vector>
#include<string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <regex> 
using namespace std;
class Finder
{

	public:
		unsigned int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) //Single function which finds the function definition
		{
			string funcName = strFunctionName;
			string sourceCode = strSourceCode;
			string delimiter = "\\n";
			size_t pos = 0;
			string token;
			unsigned int lineNo = 0;
			int found = 0;
			int confusion = 0;
			string openingBrac = "{";

		  

		    regex funcDefSameLine("(.*)("+funcName+"\\(.*\\)\\{.*)(.*)");// opening flower brackets in same line

		    regex funcDefNewLine("(.*)("+funcName+"\\(.*\\))");// opening flower brackets in next line


			while ((pos = sourceCode.find(delimiter)) != std::string::npos)// check line by line
			{
				lineNo++;
			    token = sourceCode.substr(0, pos);
				if(confusion == 1 && token.find(openingBrac) == 0)
				{
					found = 1;
					lineNo--;
					break;

				}
				else
				{
					confusion = 0;
				}
				if ( regex_match(token, funcDefSameLine) ) 
				{
					found = 1;
					break;
				}
				if(regex_match(token, funcDefNewLine))
				{
					confusion = 1;
				}
				

			    sourceCode.erase(0, pos + delimiter.length());
			}
			
			/*Start Last line condition */
			if (regex_match(sourceCode, funcDefSameLine) && found == 0) 
			{
				lineNo++;
				found = 1;
			}

			if(confusion == 1 && sourceCode.find(openingBrac) == 0 && found == 0)
			{
				found = 1;
			}
			/*End Last line condition */

			if(found == 1)
			{
				return lineNo;
			}
			else
			{
				return 0;	
			}

		}
		
		


};
int main()
{
	Finder d = Finder();
	cout<<d.FindFunctionDefn("func2", "int func1(){ return 0; }\\n int func2(){ return 1; }\\n" "int main(int argc, char*argv[]){ return func2(); }\\n")<<endl;
	
	return 0;
}
