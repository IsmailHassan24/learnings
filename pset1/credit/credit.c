#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long Number = 0;
    {
        // Prompt user for their credit card number
        Number = get_long("Number: ");
    }
    int m = (Number / 1000000000000000) % 10; //== 5;
    int m1 = (Number / 100000000000000) % 10; //== 1;
    int m2 = (Number / 100000000000000) % 10; //== 2;
    int m3 = (Number / 100000000000000) % 10; //== 3;
    int m4 = (Number / 100000000000000) % 10; //== 4;
    int m5 = (Number / 100000000000000) % 10; //== 5;
    int n = (Number / 1000000000000) % 10;
    int n2 = (Number / 1000000000000000) % 10;
    int an = (Number / 100000000000000) % 10; //== 3
    int an1 = (Number / 10000000000000) % 10; //== 4
    int an2 = (Number / 10000000000000) % 10;
    // VISA 13 Digit and 16 Digit - First Digit Calculation and Condtional Statement
    n = (Number / 1000000000000) % 10;
    n2 = (Number / 1000000000000000) % 10;
    if (n == 4 || n2 == 4)
    {
        int LastDigit = Number % 10;
        int TwotoLD = (Number / 10) % 10;
        int ThrtoLD = (Number / 100) % 10;
        int FoutoLD = (Number / 1000) % 10;
        int FiftoLD = (Number / 10000) % 10;
        int SixtoLD = (Number / 100000) % 10;
        int SevtoLD = (Number / 1000000) % 10;
        int EigtoLD = (Number / 10000000) % 10;
        int NintoLD = (Number / 100000000) % 10;
        int TentoLD = (Number / 1000000000) % 10;
        int EletoLD = (Number / 10000000000) % 10;
        int TwetoLD = (Number / 100000000000) % 10;
        int ThitoLD = (Number / 1000000000000) % 10;
        int FourttoLD = (Number / 10000000000000) % 10;
        int FifttoLD = (Number / 100000000000000) % 10;
        int SixttoLD = (Number / 1000000000000000) % 10;
        int LastDigitM1 = LastDigit % 10;
        int LastDigitM2 = (LastDigit / 10) % 10;
        int TwotoLDM1 = (TwotoLD * 2) % 10;
        int TwotoLDM2 = ((TwotoLD * 2) / 10) % 10;
        int FoutoLDM1 = (FoutoLD * 2) % 10;
        int FoutoLDM2 = ((FoutoLD * 2) / 10) % 10;
        int SixtoLDM1 = (SixtoLD * 2) % 10;
        int SixtoLDM2 = ((SixtoLD * 2) / 10) % 10;
        int EigtoLDM1 = (EigtoLD * 2) % 10;
        int EigtoLDM2 = ((EigtoLD * 2) / 10) % 10;
        int TentoLDM1 = (TentoLD * 2) % 10;
        int TentoLDM2 = ((TentoLD * 2) / 10) % 10;
        int TwetoLDM1 = (TwetoLD * 2) % 10;
        int TwetoLDM2 = ((TwetoLD * 2) / 10) % 10;
        int FourttoLDM1 = (FourttoLD * 2) % 10;
        int FourttoLDM2 = ((FourttoLD * 2) / 10) % 10;
        int SixttoLDM1 = (SixttoLD * 2) % 10;
        int SixttoLDM2 = ((SixttoLD * 2) / 10) % 10;
        int ProductDigit1 = TwotoLDM1 + TwotoLDM2 + FoutoLDM1 + FoutoLDM2 + SixtoLDM1 + SixtoLDM2 + EigtoLDM1 + EigtoLDM2 +
                            TentoLDM1 + TentoLDM2 + TwetoLDM1 + TwetoLDM2 + FourttoLDM1 + FourttoLDM2 + SixttoLDM1 + SixttoLDM2;
        int ProductDigit2 = LastDigit + ThrtoLD + FiftoLD + SevtoLD + NintoLD + EletoLD + ThitoLD + FifttoLD;
        int SumDigit = ProductDigit1 + ProductDigit2;
        if (SumDigit % 10 == 0)
        {
            printf("VISA\n");
        }
        else if (SumDigit % 10 > 0 || SumDigit % 10 < 0)
        {
            printf("INVALID\n");
        }
    }
    // AMEX condtional
    else if ((an == 3) && (an1 == 4 || an2 == 7))
    {
        int ALastDigit = Number % 10;
        int ATwotoLD = (Number / 10) % 10;
        int AThrtoLD = (Number / 100) % 10;
        int AFoutoLD = (Number / 1000) % 10;
        int AFiftoLD = (Number / 10000) % 10;
        int ASixtoLD = (Number / 100000) % 10;
        int ASevtoLD = (Number / 1000000) % 10;
        int AEigtoLD = (Number / 10000000) % 10;
        int ANintoLD = (Number / 100000000) % 10;
        int ATentoLD = (Number / 1000000000) % 10;
        int AEletoLD = (Number / 10000000000) % 10;
        int ATwetoLD = (Number / 100000000000) % 10;
        int AThitoLD = (Number / 1000000000000) % 10;
        int AFourttoLD = (Number / 10000000000000) % 10;
        int AFifttoLD = (Number / 100000000000000) % 10;
        int ALastDigitM1 = ALastDigit % 10;
        int ALastDigitM2 = (ALastDigit / 10) % 10;
        int ATwotoLDM1 = (ATwotoLD * 2) % 10;
        int ATwotoLDM2 = ((ATwotoLD * 2) / 10) % 10;
        int AFoutoLDM1 = (AFoutoLD * 2) % 10;
        int AFoutoLDM2 = ((AFoutoLD * 2) / 10) % 10;
        int ASixtoLDM1 = (ASixtoLD * 2) % 10;
        int ASixtoLDM2 = ((ASixtoLD * 2) / 10) % 10;
        int AEigtoLDM1 = (AEigtoLD * 2) % 10;
        int AEigtoLDM2 = ((AEigtoLD * 2) / 10) % 10;
        int ATentoLDM1 = (ATentoLD * 2) % 10;
        int ATentoLDM2 = ((ATentoLD * 2) / 10) % 10;
        int ATwetoLDM1 = (ATwetoLD * 2) % 10;
        int ATwetoLDM2 = ((ATwetoLD * 2) / 10) % 10;
        int AFourttoLDM1 = (AFourttoLD * 2) % 10;
        int AFourttoLDM2 = ((AFourttoLD * 2) / 10) % 10;
        int AProductDigit1 = ATwotoLDM1 + ATwotoLDM2 + AFoutoLDM1 + AFoutoLDM2 + ASixtoLDM1 + ASixtoLDM2 + AEigtoLDM1 + AEigtoLDM2 +
                             ATentoLDM1 + ATentoLDM2 + ATwetoLDM1 + ATwetoLDM2 + AFourttoLDM1 + AFourttoLDM2;
        int AProductDigit2 = ALastDigit + AThrtoLD + AFiftoLD + ASevtoLD + ANintoLD + AEletoLD + AThitoLD + AFifttoLD;
        int ASumDigit = AProductDigit1 + AProductDigit2;
        if (ASumDigit % 10 == 0)
        {
            printf("AMEX\n");
        }
        else if (ASumDigit % 10 > 0 || ASumDigit % 10 < 0)
        {
            printf("INVALID\n");
        }
    }
    // MASTERCARD
    else if ((m == 5) && (m1 == 1 || m2 == 2 || m3 == 3 || m4 == 4 || m5 == 5))
    {
        int ALastDigit = Number % 10;
        int ATwotoLD = (Number / 10) % 10;
        int AThrtoLD = (Number / 100) % 10;
        int AFoutoLD = (Number / 1000) % 10;
        int AFiftoLD = (Number / 10000) % 10;
        int ASixtoLD = (Number / 100000) % 10;
        int ASevtoLD = (Number / 1000000) % 10;
        int AEigtoLD = (Number / 10000000) % 10;
        int ANintoLD = (Number / 100000000) % 10;
        int ATentoLD = (Number / 1000000000) % 10;
        int AEletoLD = (Number / 10000000000) % 10;
        int ATwetoLD = (Number / 100000000000) % 10;
        int AThitoLD = (Number / 1000000000000) % 10;
        int AFourttoLD = (Number / 10000000000000) % 10;
        int AFifttoLD = (Number / 100000000000000) % 10;
        int ASixttoLD = (Number / 1000000000000000) % 10;
        int ALastDigitM1 = ALastDigit % 10;
        int ALastDigitM2 = (ALastDigit / 10) % 10;
        int ATwotoLDM1 = (ATwotoLD * 2) % 10;
        int ATwotoLDM2 = ((ATwotoLD * 2) / 10) % 10;
        int AFoutoLDM1 = (AFoutoLD * 2) % 10;
        int AFoutoLDM2 = ((AFoutoLD * 2) / 10) % 10;
        int ASixtoLDM1 = (ASixtoLD * 2) % 10;
        int ASixtoLDM2 = ((ASixtoLD * 2) / 10) % 10;
        int AEigtoLDM1 = (AEigtoLD * 2) % 10;
        int AEigtoLDM2 = ((AEigtoLD * 2) / 10) % 10;
        int ATentoLDM1 = (ATentoLD * 2) % 10;
        int ATentoLDM2 = ((ATentoLD * 2) / 10) % 10;
        int ATwetoLDM1 = (ATwetoLD * 2) % 10;
        int ATwetoLDM2 = ((ATwetoLD * 2) / 10) % 10;
        int AFourttoLDM1 = (AFourttoLD * 2) % 10;
        int AFourttoLDM2 = ((AFourttoLD * 2) / 10) % 10;
        int ASixttoLDM1 = (ASixttoLD * 2) % 10;
        int ASixttoLDM2 = ((ASixttoLD * 2) / 10) % 10;
        int MProductDigit1 = ATwotoLDM1 + ATwotoLDM2 + AFoutoLDM1 + AFoutoLDM2 + ASixtoLDM1 + ASixtoLDM2 + AEigtoLDM1 + AEigtoLDM2 +
                             ATentoLDM1 + ATentoLDM2 + ATwetoLDM1 + ATwetoLDM2 + AFourttoLDM1 + AFourttoLDM2 + ASixttoLDM1 +
                             ASixttoLDM2;
        int MProductDigit2 = ALastDigit + AThrtoLD + AFiftoLD + ASevtoLD + ANintoLD + AEletoLD + AThitoLD + AFifttoLD;
        int MSumDigit = MProductDigit1 + MProductDigit2;
        if (MSumDigit % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (MSumDigit % 10 < 0 || MSumDigit % 10 > 0)
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

/* #include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string str = get_string("Number: ");
    long number = atol(str);
    long length = strlen(str);
    int digits[16];

    for (int i = 0; i < length; i++)
    {
        digits[i] = number % 10;
        number = number / 10;o
    }

    if ((length == 15 && digits[14] == 3 && digits[13] == 4) || digits[13] == 7)
    {
        printf("AMEX\n");
    }
    else if ((length == 16 && digits[15] == 5 && digits[14] == 1) || digits[14] == 2 || digits[14] == 3 || digits[14] == 4 ||
digits[14] == 5)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || (length == 16 && digits[12] == 4) || digits[15] == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        printf("Length: %li\n", length);
        printf("First Digit: %i\n", digits[14]);
        printf("Second Digit: %i\n", digits[13]);
    }
}
*/