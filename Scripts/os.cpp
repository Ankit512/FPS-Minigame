#include <iostream>

using namespace std;

//Compile: g++ deadlocked-processes-simulator.cpp
//Execute: ./a.out

//Description: This program simulates the execution of 3 processes that will forever be stuck in a deadlock. Each process is looking for a particular person, but each process also can release a person another process is looking for.
//			This program is set up in such a way in which none of the processes will be able to ever find the person that another process could release theoretically.
//			Press ctrl+c to stop the program from running infinitely.

int ferris_bueller = 0;  //Represents Ferris Bueller
int waldo = 0;           //Represents Waldo
int carmen_sandiego = 0; //Represents Carmen Sandiego

int found_someone = 0; //Used to determine if any of the processes have found someone or not

//Release Ferris Bueller, allowing a process to find him
void release_ferris_bueller()
{
    ferris_bueller = 1; //Set Ferris Bueller to found
}

//Look for Ferris Bueller
void find_ferris_bueller()
{
    //If Ferris Bueller is found: Print that he was caught
    //Else: Ask for Bueller when taking attendance
    if (ferris_bueller)
    {
        cout << "Caught ya Ferris Bueller!" << endl;
    }
    else
    {
        cout << "Bueller?...Bueller?...Bueller?" << endl;
    }
}

//Release Waldo, allowing a process to find him
void release_waldo()
{
    waldo = 1; //Set Waldo to found
}

//Look for Waldo
void find_waldo()
{
    //If Waldo is found: Print that he was found
    //Else: Ask where Waldo is
    if (waldo)
    {
        cout << "There's Waldo!" << endl;
    }
    else
    {
        cout << "Where's Waldo?" << endl;
    }
}

//Release Carmen Sandiego, allowing a process to find her
void release_carmen_sandiego()
{
    carmen_sandiego = 1;
}

//Look for Carmen Sandiego
void find_carmen_sandiego()
{
    //If Carmen Sandiego is found: Print that she was found
    //Else: Ask where in the world she is
    if (carmen_sandiego)
    {
        cout << "Carmen Sandiego is here!" << endl;
    }
    else
    {
        cout << "Where in the world is Carmen Sandiego?" << endl;
    }
}

//Process looking for Ferris Bueller
void process1()
{
    find_ferris_bueller();

    //If Ferris Bueller is found: Release Waldo, allowing another process to find him
    if (ferris_bueller)
    {
        release_waldo();
        found_someone = 1;
    }
}

//Process looking for Waldo
void process2()
{
    find_waldo();

    //If Waldo is found: Release Carmen Sandiego, allowing another process to find her
    if (waldo)
    {
        release_carmen_sandiego();
        found_someone = 1;
    }
}

//Process looking for Carmen Sandiego
void process3()
{
    find_carmen_sandiego();

    //If Carmen Sandiego is found: Release Ferris Bueller, allowing another process to find him
    if (carmen_sandiego)
    {
        release_ferris_bueller();
        found_someone = 1;
    }
}

int main()
{
    while (!found_someone)
    {
        process1();
        process2();
        process3();
    }
}