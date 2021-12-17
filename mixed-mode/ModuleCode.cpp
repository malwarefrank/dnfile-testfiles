using namespace System;
#include <stdio.h>

unsigned char key[] = { 'A', 'B', 'C', 'D' };
unsigned char message[22] = {
    0x70, 0x01, 0x96, 0xDB, 0x60, 0xF4, 0x4C, 0x2F,
    0xAF, 0x49, 0x46, 0xA1, 0xC9, 0xD6, 0xAA, 0x27,
    0x72, 0x2E, 0xB4, 0x5C, 0xE4, 0x67
};


typedef struct RC4_STATE_
{
    int x, y, m[256];
}RC4_STATE, * PRC4_STATE;

void rc4_init(PRC4_STATE s, unsigned char* key, int length)
{
    int i, j, k, * m, a;

    s->x = 0;
    s->y = 0;
    m = s->m;

    for (i = 0; i < 256; i++)
    {
        m[i] = i;
    }

    j = k = 0;

    for (i = 0; i < 256; i++)
    {
        a = m[i];
        j = (unsigned char)(j + a + key[k]);
        m[i] = m[j]; m[j] = a;
        if (++k >= length) k = 0;
    }
}

void rc4_crypt(PRC4_STATE s, unsigned char* data, int length)
{
    int i, x, y, * m, a, b;

    x = s->x;
    y = s->y;
    m = s->m;

    for (i = 0; i < length; i++)
    {
        x = (unsigned char)(x + 1); a = m[x];
        y = (unsigned char)(y + a);
        m[x] = b = m[y];
        m[y] = a;
        data[i] ^= m[(unsigned char)(a + b)];
    }

    s->x = x;
    s->y = y;
}


int main(int argc, char* argv[])
{
    RC4_STATE rc4;

    rc4_init(&rc4, (unsigned char*)key, sizeof(key));
    rc4_crypt(&rc4, message, sizeof(message));

    printf("unmanaged  : %s\n", message);

    System::String^ managed_message = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char*)message);
    Console::WriteLine("managed    : {0}", managed_message);
    
    return 0;
}