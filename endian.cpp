#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint16_t word=1; //0x001;

    uint16_t *first_byte=(uint16_t*)(&word);

    bool flag= !(*first_byte);
    cout<<first_byte<<endl;
    if(flag)
    {
        cout<<"Big Endian"<<endl;
    }
    else
    {
        cout<<"Little endian"<<endl;
    }

    uintptr_t address;
    cin>>hex>>address;
    cout<<hex<<address<<endl;
    uint32_t* s=(uint32_t*)(address);
    cout<<*s<<endl;

}