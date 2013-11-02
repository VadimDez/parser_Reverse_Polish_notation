#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
void inserimento(char vet[]);
void stampa(char vet[]);
void parser(char vet[]);

#define operatore vet[i] == '+' || vet[i] == '-' || vet[i] == '/' || vet[i] == '*'

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char vet[20];
    while(1)
    {
        inserimento(vet);
        stampa(vet);
        parser(vet);
        stampa(vet);
    }

    return a.exec();
}

void inserimento(char vet[])
{
    cout << "Inserisci: \n";
    cin.getline(vet,20);
}

void stampa(char vet[])
{
    cout << vet << endl;
}

void parser(char vet[])
{
    /*char temp;
    for(int i=0;i<20;i++)
    {
        if(vet[i] == '(' )
        {
            if(i != 0) //se primo elemento leva la '('
            {          //se non primo mette ','
                vet[i] = ',';
            }
            else
            {
                vet[i] = ' ';
            }
            do
            {
                i++;
                if(operatore)
                {
                    temp = vet[i];
                    vet[i] = ',';
                }
            }while(vet[i] != ')');
            vet[i] = temp;
        }
        else
        {
            char appoggio;
            if(operatore)
            {
                if(vet[i] == '\0' && (vet[i-1] >= '0' && vet[i-1] <= '9')) // per aggiungere in fondo il operatore
                {
                    vet[i] = temp;
                }
                else
                {
                    temp = vet[i];
                    vet[i] = ',';
                    do
                    {
                        i++;
                        if(operatore)
                        {
                            appoggio = vet[i];
                            vet[i] = temp;
                        }
                        else
                        {
                            if(vet[i] == '\0' || vet[i] == ',')
                            {
                                vet[i] = temp;
                            }
                        }
                    }while(vet[i] != temp);
                    temp = appoggio;
                }
            }
        }
    }*/
    char stackVal[20];
    char stackOp[20];
    int i(0),countVal(0),countOp(0);
    do
    {
        if(vet[i] != '\0')
        {
            if(vet[i] != ' ')
            {
                if(vet[i] == '+' || vet[i] == '-' || vet[i] == '/' || vet[i] == '*')
                {
                    if(countVal > 1 && stackVal[countVal] != ' ')
                    {
                        stackVal[countVal] = vet[i];
                        countVal++;
                    }
                    stackOp[countOp] = vet[i];
                    countOp++;
                }
                else
                {
                    if(countVal > 1 && stackVal[countVal] != ' ')
                    {
                        stackVal[countVal] = vet[i];
                        countVal++;
                    }
                    stackVal[countVal] = vet[i];
                    countVal++;
                }
            }
        }
        i++;

    }while(vet[i-1] != '\0' || vet[i] < 20);
    for(int c=0;c<20;c++)
    {
        vet[c] = ' ';
    }
    for(i=0;i<countVal;i++)
    {
        vet[i] = stackVal[i];
    }
    for(int count=0;count < countOp;count++,i++)
    {
        vet[i] = stackOp[countOp-count-1];
    }
}
