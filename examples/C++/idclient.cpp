//
//  Irondomo Protocol client example
//  Uses the idcli API to hide all IDP aspects
//

//  Lets us build this source without creating a library
#include "idpcliapi.cpp"
#include <iostream>

int main (int argc, char *argv [])
{
    int verbose = (argc > 1 && streq (argv [1], "-v"));
    IDP::IDPClient *client = new IDP::IDPClient("tcp://127.0.0.1:5001", "Client", true, 2500, 3);
    client->setupCurve("4BW)6Jg0+&}3Mwq*dJTMoG^rHbD#b!2SUmr7<H0#", "aS&Z4DU7#rpbsF+.r9Ek7%Id2FzftXA^egj+VWmp", ".8Q^k*3E/4-Wg4()r^(4yTk2>qvZFDW?mXUyRPvr");

    client->startClient();

    int count;
    for (count = 0; count < 1000; count++) {
        std::vector<std::string> messageVec;
        messageVec.push_back("Hello world p1 ->" + std::to_string(count));
        messageVec.push_back("Hello world p2 ->" + std::to_string(count));
        try
        {
            std::vector<std::string> res = client->send("echo", messageVec);
            for (auto it=res.begin(); it!=res.end(); it++)
                std::cout << *it << std::endl;
        }
        catch (std::exception &e)
        {
                std::cout << "Exception Caught: " << e.what() << std::endl;
                break;
        }

    }
    printf ("%d requests/replies processed\n", count);

    delete client;

    return 0;
}
