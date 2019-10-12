/*
Copyright (C) 2019  JingWeiZhangHuai
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#define HELP_FILE "./help.txt"

#define fgets(Buff,Num,F) mException((fgets(Buff,Num,F)==NULL),EXIT,"file read error")

#define HELP_INFOMATION(name) {\
    int arg_flag;\
    mStringArgument(argc,argv,"-help",&arg_flag);\
    if(arg_flag) {mToolHelp(name); return 1;}\
    mStringArgument(argc,argv,"v",&arg_flag);\
    if(arg_flag) {mToolHelp("version"); return 1;}\
}

void mToolHelp(char *name)
{
    FILE *f;
    char buff[2048];
    int len;
    
    len = strlen(name);
    
    f = fopen(HELP_FILE,"r");
    
    while(!feof(f))
    {
        fgets(buff,2048,f);
        if(buff[0] == '[')
        {
            if((strspn(buff+1,name)>=len)&&(buff[len+1] == ']'))
                break;
        }
    }
    
    fgets(buff,2048,f);
    while((buff[0] != '[')&&(!feof(f)))
    {
        printf("%s",buff);
        fgets(buff,2048,f);
    }
    
    fclose(f);
}
