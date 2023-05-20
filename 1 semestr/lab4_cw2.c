#include<stdio.h>

float dodawanie(float a, float b){
    float wynik;
    wynik = a + b;
    return wynik;
}
float odejmowanie(float a, float b){
    float wynik;
    wynik = a - b;
    return wynik;
}
float mnozenie(float a, float b){
    float wynik;
    wynik = a * b;
    return wynik;
}
float dzielenie(float a, float b){
    float wynik;
    wynik = a / b;
    return wynik;
}

void main(void){
    float a, b, wynik;
    char doing;
    printf("Podaj wartość a = ");
    scanf("%f",&a);
    printf("Podaj wartość b = ");
    scanf("%f",&b);
    printf("jakie działanie chcesz wykonać(+, -, *, /) -  ");
    scanf("%s", &doing);
    switch (doing)
    {
    case '+':
        wynik = dodawanie(a, b);
        break;
    case '-':
        wynik = odejmowanie(a, b);
        break;
    case '*':
        wynik = mnozenie(a, b);
        break;
    case '/':
        if(b != 0)
        {
            wynik = dzielenie(a, b);
            break;
        }
        else
        {
            printf("Nie można dzielić przez zero!");
            break;
        }
    }
    printf("%f %c %f = %f", a, doing, b, wynik);

}