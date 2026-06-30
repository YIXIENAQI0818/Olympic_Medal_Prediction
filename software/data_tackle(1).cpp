#include<bits/stdc++.h>
using namespace std;
#define Timelength 50;
#define Programnum 50;
int trans(char* str)
{
    int k = 0;
    for(int i=0;i<strlen(str);i++)
    {
        k = k*10;
        k += str[i] - 48;
    }
    //cout<<k<<endl;
    return k;
}
bool match(char* tr1,const char* tr2)
{
    bool res = true;
    for(int i=0;i<strlen(tr2);i++)
    {
        if(tr1[i] != tr2[i])
        {
            res = false;
        }
    }
    return res;
}
int main()
{
    string country[400];
    char line[1000],*token;
    const char *md1= "No medal",*md2 = "Gold",*md3 = "Silver",*md4 = "Bronze";
    string outputfile = "patch.csv";
    FILE *file0 = fopen("grouped_df_oc.csv","r");
    if(!file0)
    {
        exit(1);
    }
    fgets(line,sizeof(line),file0);
    fgets(line,sizeof(line),file0);
    token = strtok(line,",");
    country[0] = token;
    int country_num = 1;
    while(fgets(line,sizeof(line),file0))
    {
        token = strtok(line,",");
        if(token != country[country_num-1])
        {
            country[country_num] = token;
            country_num++;
        }
    }
    fclose(file0);
    // ????????????
    int host[50] = {0},program_num[50][50] = {0},athlete_gold[50][50] = {0},athlete_silver[50][50] = {0},athlete_bronze[50][50] = {0},athlete_no[50][50] = {0},medals[50][4] = {0};
    string program_name[50],year[50];
    FILE *file01 = fopen("summerOly_programs.csv","r");
    if(!file01)
    {
        exit(1);
    }
    int years = 0;
    fgets(line,sizeof(line),file01);
    token = strtok(line,",");
    token = strtok(NULL,",");
    while(token)
    {
        year[years] = token;
        // cout<<year[years]<<endl;
        years++;
        token = strtok(NULL,",");
    }
    int programs = 0;
    while(fgets(line,sizeof(line),file01))
    {
        token = strtok(line,",");
        program_name[programs] = token;
        programs++;
        token = strtok(NULL,",");
    }
    fclose(file01);
    FILE *file4 = fopen(outputfile.data(),"w");
    if(!file4)
    {
        exit(1);
    }
    fprintf(file4,"country");
    fprintf(file4,",year");
    fprintf(file4,",host");
    for(int t=0;t<programs;t++)
    {
        fprintf(file4,",%s",program_name[t].c_str());
        // fprintf(file4,"%d",t);
        fprintf(file4,",%s",program_name[t].c_str());
        // fprintf(file4,"%d",t);
        fprintf(file4,"_gold");
        fprintf(file4,",%s",program_name[t].c_str());
        // fprintf(file4,"%d",t);
        fprintf(file4,"_silver");
        fprintf(file4,",%s",program_name[t].c_str());
        // fprintf(file4,"%d",t);
        fprintf(file4,"_bronze");
        fprintf(file4,",%s",program_name[t].c_str());
        // fprintf(file4,"%d",t);
        fprintf(file4,"_no");
    }
    fprintf(file4,",medal_gold");
    fprintf(file4,",medal_silver");
    fprintf(file4,",medal_bronze");
    fprintf(file4,"\n");
    for(int tml=0;tml<country_num;tml++)
    {
        for(int k1=0;k1<50;k1++)
        {
            for(int k2=0;k2<50;k2++)
            {
                athlete_bronze[k1][k2] = 0;
                athlete_gold[k1][k2] = 0;
                athlete_silver[k1][k2] = 0;
                athlete_no[k1][k2] = 0;
            }
        }
        // cout<<country[tml]<<endl;
        FILE *file1;
        file1 = fopen("summerOly_programs.csv","r");
        if(!file1)
        {
            exit(1);
        }
        int n=0,m=0;
        
        // int years = n;
        fgets(line,sizeof(line),file1);
        while(fgets(line,sizeof(line),file1))
        {
            token = strtok(line,",");
            // program_name[m] = token;
            token = strtok(NULL,",");
            n=0;
            while(token)
            {
                program_num[n][m] = trans(token);
                token = strtok(NULL,",");
                n++;
            }
            m++;
        }
        // cout<<"***"<<endl;
        fclose(file1);
        FILE *file2 = fopen("summerOly_medal_counts.csv","r");
        if(!file2)
        {
            exit(1);
        }
        fgets(line,sizeof(line),file2);
        m=0;
        while(fgets(line,sizeof(line),file2))
        {
            token = strtok(line,",");
            token = strtok(NULL,",");
            if(token == country[tml])
            {
                token = strtok(NULL,",");
                for(int p=m;p<years;p++)
                {
                    if(year[p] == token)
                    {
                        m=p;
                        break; 
                    }
                    
                }
                for(int i=0;i<3;i++)
                {
                    token = strtok(NULL,",");
                    medals[m][i] = trans(token);
                }
                token = strtok(NULL,",");
                token = strtok(NULL,",");
                host[m] = trans(token);
                break;
            }
        }
        while(fgets(line,sizeof(line),file2))
        {
            token = strtok(line,",");
            token = strtok(NULL,",");
            if(token != country[tml])
            {
                break;
            }
            token = strtok(NULL,",");
            for(int p=m;p<years;p++)
            {
                if(year[p] == token)
                {
                    m=p;
                    break;
                }
                
            }
            for(int i=0;i<3;i++)
            {
                token = strtok(NULL,",");
                medals[m][i] = trans(token);
            }
            token = strtok(NULL,",");
            token = strtok(NULL,",");
            host[m] = trans(token);
        }
        fclose(file2);
        FILE *file3 = fopen("grouped_df.csv","r");
        if(!file3)
        {
            exit(1);
        }
        fgets(line,sizeof(line),file3);
        m=0,n=0;
        while(fgets(line,sizeof(line),file3))
        {
            token = strtok(line,",");
            if(token == country[tml])
            {
                token = strtok(NULL,",");
                for(int p=0;p<years;p++)
                {
                    if(year[p] == token)
                    {
                        m=p;
                        break;
                    } 
                }
                token = strtok(NULL,",");
                for(int p = 0;p<programs;p++)
                {
                    if(program_name[p] == token)
                    {
                        n=p;
                        break;
                    }
                }
                // cout<<m<<" "<<n<<endl;
                token = strtok(NULL,",");
                // cout<<token<<endl;
                if(match(token,md1))
                {
                    token = strtok(NULL,",");
                    athlete_no[m][n] = trans(token);
                }
                if(match(token,md2))
                {
                    // cout<<"+++"<<endl;
                    token = strtok(NULL,",");
                    athlete_gold[m][n] = trans(token);
                }
                if(match(token,md3))
                {
                    token = strtok(NULL,",");
                    athlete_silver[m][n] = trans(token);
                }
                if(match(token,md4))
                {
                    token = strtok(NULL,",");
                    athlete_bronze[m][n] = trans(token);
                }
            }
        }
        // n = 0;
        // int cut = 0;
        // while(fgets(line,sizeof(line),file3))
        // {
        //     // cut++;
        //     // cout<<cut<<endl;
            
        //     token = strtok(line,",");
        //     if(!token)
        //         break;
        //     token = strtok(NULL,",");
        //     token = strtok(NULL,",");
        //     if(token == country[tml])
        //     {
        //         token = strtok(NULL,",");
        //         token = strtok(NULL,",");
        //         if(token == year[n+1])
        //             n++;
        //         if(token == year[n])
        //         {
        //             token = strtok(NULL,",");
        //             token = strtok(NULL,",");
        //             int i;
        //             for(i=0;i<m;i++)
        //             {
        //                 if(program_name[i] == token)
        //                     break;
        //             }
        //             token = strtok(NULL,",");
        //             token = strtok(NULL,",");
        //             // cout<<token<<endl;
        //             if(match(token,md1))
        //             {
        //                 athlete_no[n][i]++;
        //             }
        //             if(match(token,md2))
        //             {
        //                 athlete_gold[n][i]++;
        //             }
        //             if(match(token,md3))
        //             {
        //                 athlete_silver[n][i]++;
        //             }
        //             if(match(token,md4))
        //             {
        //                 athlete_bronze[n][i]++;
        //             }
        //         }
        //     }
        // }
        // while(fgets(line,sizeof(line),file3))
        // {
        //     token = strtok(line,",");
        //     if(token != country[tml])
        //     {
        //         break;
        //     }
        //     token = strtok(NULL,",");
        //     for(int p=m;p<years;p++)
        //     {
        //         if(year[p] == token)
        //         {
        //             m=p;
        //             break;
        //         }
        //     }
        //     token = strtok(NULL,",");
        //     for(int p = n;p<programs;p++)
        //     {
        //         if(program_name[p] == token)
        //         {
        //             n=p;
        //             break;
        //         }
        //     }
        //     token = strtok(NULL,",");
        //     if(match(token,md1))
        //     {
        //         token = strtok(NULL,",");
        //         athlete_no[m][n] = trans(token);
        //     }
        //     if(match(token,md2))
        //     {
        //         token = strtok(NULL,",");
        //         athlete_gold[m][n] = trans(token);
        //     }
        //     if(match(token,md3))
        //     {
        //         token = strtok(NULL,",");
        //         athlete_silver[m][n] = trans(token);
        //     }
        //     if(match(token,md4))
        //     {
        //         token = strtok(NULL,",");
        //         athlete_bronze[m][n] = trans(token);
        //     }
        // }
        fclose(file3);
        FILE *file4 = fopen(outputfile.data(),"a+");
        if(!file4)
        {
            exit(1);
        }
        for(int j=0;j<(years - 1);j++)
        {
            fprintf(file4,"%s",country[tml].c_str());
            fprintf(file4,",%s",year[j].c_str());
            // cout<<year[j]<<endl;
            fprintf(file4,",%d",host[j]);
            for(int t=0;t<programs;t++)
            {
                fprintf(file4,",");
                fprintf(file4,"%d",program_num[j][t]);
                fprintf(file4,",");
                fprintf(file4,"%d",athlete_gold[j][t]);
                fprintf(file4,",");
                fprintf(file4,"%d",athlete_silver[j][t]);
                fprintf(file4,",");
                fprintf(file4,"%d",athlete_bronze[j][t]);
                fprintf(file4,",");
                fprintf(file4,"%d",athlete_no[j][t]);
            }
            fprintf(file4,",%d",medals[j+1][0]);
            fprintf(file4,",%d",medals[j+1][1]);
            fprintf(file4,",%d",medals[j+1][2]);
            fprintf(file4,"\n");
        }
        // fprintf(file4,"\n");
        // fprintf(file4,"%s",country[tml].c_str());
        // fprintf(file4,",%s",year[years - 1].c_str());
        // // cout<<"*"<<year[j]<<endl;
        // fprintf(file4,",%d",host[years - 1]);
        // for(int t=0;t<programs;t++)
        // {
        //     fprintf(file4,",");
        //     fprintf(file4,"%d",program_num[years - 1][t]);
        //     fprintf(file4,",");
        //     fprintf(file4,"%d",athlete_gold[years - 1][t]);
        //     fprintf(file4,",");
        //     fprintf(file4,"%d",athlete_silver[years - 1][t]);
        //     fprintf(file4,",");
        //     fprintf(file4,"%d",athlete_bronze[years - 1][t]);
        //     fprintf(file4,",");
        //     fprintf(file4,"%d",athlete_no[years - 1][t]);
        // }
        // fprintf(file4,",0");
        //     fprintf(file4,",0");
        //     fprintf(file4,",0");
        // fprintf(file4,"\n");
        fclose(file4);
    }
    
    return 0;
}