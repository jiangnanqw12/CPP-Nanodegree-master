/* Streaming ints from a string with istringstream

In C++ strings can be streamed into temporary variables,
similarly to how files can be streamed into strings. 
Streaming a string allows us to work with each character individually.

One way to stream a string is to use an input string stream object
istringstream from the <sstream> header.

Once an istringstream object has been created, parts of the string
can be streamed and stored using the "extraction operator": >>.
The extraction operator will read until whitespace is reached or until the stream fails.
Execute the following code to see how this works:

*/


/////////////////////////
// Read int from file string
// 1. #include<sstream>
// 2. using std::istringstream
// can read string and stop only hit space or error(end)
/////////////////////////


#include<iostream>
#include<string>
#include<sstream>

using std::string;
using std:: cout;
using std::istringstream;

/*
myreader is a pointer, whith point to the contain of string.
if the current pointer READ(>>) the non-number or error or endoffile
the myreader will return error or 0 or false

every time you extract a contain, the myrerader will move right to next contain.
*/


void istringstream_test(){
    cout<< __func__ <<"\n";
    string a("1 2 3");
    int data;
    istringstream mystream(a);
    mystream>>data;
    cout<<data;
}


void use_isstringstream_as_boolen_read_all(){
    cout<<__func__<<"\n";
    string a="1 2 3";
    int data;
    istringstream mystream(a);
    while(mystream)
    {
        mystream>>data;
        //cout<<data<<"\n";
        if(mystream)
        {
            cout<<"success: "<<data<<"\n";
        }
        else
        {
            cout<<"fail or end\n";
        }
        
    }
}

void common_way_to_use_istringstream_in_while(){
    cout<<__func__<<"\n";
    string a="1 2 3";
    int data;
    istringstream mystream(a);
    while(mystream>>data)
    {
        cout<<"success: "<<data<<"\n";
    }
    cout<<"fail or end\n";
}



void string_with_MIX_types_not_space(){
/*
In the stream example above, the string contained only whitespaces
and characters which could be converted to ints.

If the string has mixed types, more care is needed to process the string.
In the following example,
the type char is used, which is a type that can hold only a single ASCII character.
*/
    cout << __func__<< "\n";

    string b("1,2,3,4,6q7p8o9");

    istringstream mixstring(b);
    //need two type of tmp value
    char c;
    int n;

    /*
        !! notice that the 9 was not printed

        mixstring >> n >> c

        tried to stream an int followed by a char.
        Since there was no char after the 9, the stream
        failed and the while loop exited.
    */
    while(mixstring>>n>>c)
    {
        cout<<"int: "<<n<<" ";
        cout<<"char: "<<c<<"\n";
    }
}


int main(){
    //stream with all INT type
    istringstream_test();
    use_isstringstream_as_boolen_read_all();
    common_way_to_use_istringstream_in_while();

    //stream with MIX type
    //the INT spreated by only one char not space
    string_with_MIX_types_not_space();
}
