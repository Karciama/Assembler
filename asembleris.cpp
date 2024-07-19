#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int dydis = 10;
    int arr[10]{};
    char skaiciai[11]{};

    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    __asm
    {
        push eax
        push ebx
        push ecx
        push edx

        mov eax, 0
        mov ebx, 0
        mov ecx, 0
        mov edx, 0
        /*
        jmp = normalus jumpas
        jz = jumpas jei 0 (zero)
        je = jei lygu (equal)
        jg = jei didesnis (greater)
        jl = jei mazesnis (lesser)
        */
        mov ecx, dydis
        lea ebx, arr 
        lea edx, skaiciai
        jmp ivedimas
        error :
            mov dydis, 11
            jmp galas
        zero :
            mov dydis, 0
            add ebx, 4
            dec ecx
            jz galas

        ivedimas :
            cmp[ebx], 0
            je zero
            cmp[ebx], 9
            jg error
            mov eax, [ebx]
            add eax, '0'
            mov[edx], al
            inc edx
            add ebx, 4
            dec ecx
            jnz ivedimas
            galas :
        mov byte ptr[edx], 0

            pop edx
            pop ecx
            pop ebx
            pop eax
    }

    switch (dydis)
    {
    case 10:
        cout << skaiciai;
        break;
    case 0:
        cout << skaiciai << " skaiciu sarase yra 0";
        break;
    case 11:
        cout << "sarase yra nevienazenkliu skaiciu";
        break;
    }
    return 0;
}
