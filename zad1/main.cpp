#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input( "input.txt", fstream::in );
    ofstream output("output.txt", fstream::out);
    ofstream temp( "temp.txt", fstream::out);

    int all_objects = 0;
    int bad_objects = 0;

    if ( input.is_open())
    {
        char c;
        string object;
        int i = 1;
        bool valid_object = false;

        while ( input >> c )
        {
            if ( c == '1' && !valid_object )
                valid_object = true;

            object.push_back( c );

            if ( i++ == 8 )
            {
                int control_bit=object[object.size() - 1] - '0';

                if (( control_bit != ++all_objects % 2 ) || !valid_object )
                    bad_objects++;
                else
                    temp << object;

                valid_object = false;
                i = 1;
                object = "";
            }
        }
    }
    else
        return 1;

    output << "Wszystkie obiekty: " << all_objects << "\n" << "Obiekty z błędami: " << bad_objects << "\n";
    input.close();
    temp.close();
    temp.open("temp.txt", fstream::in);
    output << temp.rdbuf();
    output.close();
    temp.close();
    remove("temp.txt");

    return 0;
}