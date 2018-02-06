#include <iostream>
#include <string>
#include <string.h>
#include  "caffe/util/io.hpp"


using namespace caffe;
using namespace std;

void pbtxt2pb(const char* szFileName)
{
  NetParameter proto;
  if (ReadProtoFromTextFile(szFileName,&proto))
    {
      cout << "read "  << szFileName << " ok" << endl;
      string name;
      name = szFileName;
      name += ".pb";
      WriteProtoToBinaryFile(proto,name.c_str());
    }
}

void dumppbtxt(const char* szFileName)
{
  NetParameter proto;
  if (ReadProtoFromBinaryFile(szFileName,&proto))
    {
      cout << "read "  << szFileName << " ok" << endl;
      string name;
      name = szFileName;
      name += ".txt";
      WriteProtoToTextFile(proto,name.c_str());
    }
  else
    cout << "read " << szFileName << " fail." << endl;
}

void usage(const char* szName)
{
  cout << szName << " usage:" << endl;
  cout << "\t" << szName << " txt-file-name   \tconvert prototxt to binary" << endl;
  cout << "\t" << szName << " -t binary-file-name  \tconvert proto binary to txt" << endl;
}

int main(int argc, const char** argv)
{
  if (argc == 2)
    {
      pbtxt2pb(argv[1]);
    }
  else if (argc > 2)
    {
      if (strcmp(argv[1],"-t")==0)
        {
          cout << "staring dump file " << argv[2] << endl;
          dumppbtxt(argv[2]);
        }
    }
  else
    usage(argv[0]);
}
