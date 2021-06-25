#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int main(int argc,char ** argv)
{
    char line[N];
    FILE *fp;
    string cmd = "touch ";
    // system call
    char *syscmd =const_cast<char*> (cmd.data());
    
    char *sysCommand=strcat(syscmd,argv[1]);
    strcat(sysCommand,".cpp");
    if ((fp = popen(sysCommand, "r")) == NULL)
    {
        cout << "error" << endl;
    }
    
    pclose(fp);
    ofstream outfile;
    char *filename=strcat(argv[1],".cpp");
    outfile.open(filename);
    outfile<<"//"<<endl;
    outfile<<"#include<bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\n";
    outfile<<endl;
    outfile<<"int main()\n";
    outfile<<"{\n";
    outfile<<"    ios::sync_with_stdio(false);\n";
    outfile<<"    cin.tie(NULL);\n";
    outfile<<"}"<<endl;
    return 0;
}