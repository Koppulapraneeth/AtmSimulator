#include<stdio.h>

int main()
{
    int option, language;
    double balance = 1000.00, amount;

    printf("------Welcome To Our ATM------\n");
    printf("Please Select Your Language\n");
    printf("1. English\n2. Telugu\n3. Hindi\n");
    printf("Enter Your Language :- ");
    scanf("%d", &language);

    if (language < 1 || language > 3) {
        printf("Invalid Option. Selecting English by default as it is the default language.\n");
        language = 1;
    }

#define ATMPIN 1735

    int pin, attempts = 0;
    do {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &pin);
        if (pin != ATMPIN) {
            printf("\nIncorrect PIN. Try again.\n");
            attempts++;
        } else {
            break;
        }
    } while (attempts < 3);

    if (attempts == 3) {
        printf("Too many incorrect attempts. Exiting.\n");
        return 1;
    }

    do {
        if (language == 1) {
            printf("\n1. Check Balance\n2. Cash Deposit\n3. Cash Withdraw\n4. Exit\n");
            printf("Enter Your Option :- ");
        } else if (language == 2) {
            printf("\n1. మీ బ్యాలెన్స్ మొత్తాన్ని తనిఖీ చేయండి\n2. నగదు డిపాజిట్\n3. నగదు ఉపసంహరణ\n4. నిష్క్రమించు\n");
            printf("మీ ఎంపికను నమోదు చేయండి :- ");
        } else {
            printf("\n1. अपनी शेष राशि जांचें\n2. नकद जमा\n3. नकद निकासी\n4. बाहर निकलना\n");
            printf("अपना विकल्प दर्ज करें :- ");
        }

        scanf("%d", &option);

        if (option == 1) {
            if (language == 1)
                printf("₹%.2lf is Your Balance Amount\n", balance);
            else if (language == 2)
                printf("మీ బ్యాలెన్స్ మొత్తం: ₹%.2lf\n", balance);
            else
                printf("आपकी शेष राशि ₹%.2lf है\n", balance);
        } else if (option == 2) {
            if (language == 1)
                printf("Please Enter Your Deposit Amount :- ");
            else if (language == 2)
                printf("దయచేసి మీ డిపాజిట్ మొత్తాన్ని నమోదు చేయండి :- ");
            else
                printf("कृपया अपनी जमा राशि दर्ज करें :- ");

            scanf("%lf", &amount);
            if (amount >= 100) {
                balance += amount;
                if (language == 1)
                    printf("Deposit Successful\n");
                else if (language == 2)
                    printf("డిపాజిట్ విజయవంతమైంది\n");
                else
                    printf("जमा सफल\n");
            } else {
                if (language == 1)
                    printf("You Can't Deposit less than 100\n");
                else if (language == 2)
                    printf("మీరు 100 కంటే తక్కువ డిపాజిట్ చేయలేరు\n");
                else
                    printf("आप 100 से कम जमा नहीं कर सकते\n");
            }
        } else if (option == 3) {
            if (language == 1)
                printf("Enter Withdraw Amount :- ");
            else if (language == 2)
                printf("నగదు ఉపసంహరణ మొత్తం నమోదు చేయండి :- ");
            else
                printf("निकासी राशि दर्ज करें :- ");

            scanf("%lf", &amount);
            if (amount < 100) {
                if (language == 1)
                    printf("You can't withdraw less than ₹100\n");
                else if (language == 2)
                    printf("మీరు ₹100 కంటే తక్కువ ఉపసంహరించలేరు\n");
                else
                    printf("आप ₹100 से कम राशि नहीं निकाल सकते\n");
            } else if (amount <= balance) {
                balance -= amount;
                if (language == 1)
                    printf("Withdraw Successful\n");
                else if (language == 2)
                    printf("ఉపసంహరణ విజయవంతం\n");
                else
                    printf("निकासी सफल रही\n");
            } else {
                if (language == 1)
                    printf("Insufficient Balance\n");
                else if (language == 2)
                    printf("అసమర్థ బ్యాలెన్స్\n");
                else
                    printf("पर्याप्त शेष नहीं है\n");
            }
        } else if (option != 4) {
            if (language == 1)
                printf("Invalid Option. Try again.\n");
            else if (language == 2)
                printf("చెల్లని ఎంపిక. మళ్లీ ప్రయత్నించండి.\n");
            else
                printf("अमान्य विकल्प. फिर से प्रयास करें.\n");
        }

    } while (option != 4);

    if (language == 1)
        printf("Thank you for using our ATM\n");
    else if (language == 2)
        printf("మా ఏటిఎంను ఉపయోగించినందుకు ధన్యవాదాలు\n");
    else
        printf("हमारा एटीएम उपयोग करने के लिए धन्यवाद\n");

    return 0;
}
