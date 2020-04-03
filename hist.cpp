// ASCI histogram program.
//
// Fun exercise in learning cpp. Takes stream from stdin
// and counts occurances of each ASCI character and 
// generates a normalized bar chart. 
//
// Instructions:
// From your favorite command line, do the following
// 
// some_text_file.txt | ./hist
//

#include <iostream>
#include <vector>
#include <iomanip>

//ASCI character range of interest
const int ASCI_START = 32;
const int ASCI_END = 126;

//stdin buffer length
const int DEFAULT_BUF_LENGTH = 16;

//Maximum bar chart height, used for normalization
const int MAX_HEIGHT = 15;

//Define the function stubs
void print_asci();
void print_asci_line();
void parse_input(std::vector<int>&);
int find_max_num(const std::vector<int>&);
int find_max_index(const std::vector<int>&);
void print_bars(const std::vector<int>&);
void normalize(std::vector<int> &);



int main()
{

    //Vector containing character counts
    std::vector<int> char_counts(ASCI_END-ASCI_START);

    //Parse stin for data
    parse_input(char_counts);

    //Normalize the vector
    normalize(char_counts);

    //Print bars line by line
    print_bars(char_counts);

    //Print the ASCI characters on the x-axis
    print_asci_line();
    return 0;
}


void print_asci()
{
    std::cout<<std::endl;

    char c;

    
    for(int idx = ASCI_START; idx <= ASCI_END; idx++)
    {   
        c = idx;

        if ( (idx-ASCI_START) % 10 == 0) std::cout << std::endl;
        std::cout << std::setw(3) << idx;
        std::cout << " : ";
        std::cout << std::setw(1) << c;
        std::cout << "    ";

    }

    std::cout << std::endl;

}

void print_bars(const std::vector<int> &counts)
{
    int max = find_max_num(counts)
    for (int y = max; y > 0; y--)
    {
        for(int x=0; x<(ASCI_END-ASCI_START);x++)
        {   
            if (x==0) std::cout << "|  ";
    
            if (counts[x]>=y)
            {
                std::cout << '#';
            }
            else
            {
                std::cout << ' ';
            }
        }
    
        std::cout << std::endl;
    }
}

void normalize(std::vector<int> &v)
{
    int max = find_max_num(v);
    int nf = max/MAX_HEIGHT;
    for (int &element : v)
    {
        element/=nf;
    }
}


void print_asci_line()
{
    for (char idx = ASCI_START; idx <= ASCI_END; idx++)
    {
        std::cout<< "_";
    }

    std::cout<<std::endl;

    for (char idx = ASCI_START; idx <= ASCI_END; idx++)
{       
        if (idx==ASCI_START) std::cout << "|  ";

        std::cout << idx;
    }

    std::cout << std::endl << std::endl;;
}




int find_max_num(const std::vector<int> &counts)
{
    int max = 0;
    for (int item : counts)
    {
        if (item > max) max=item;
    }

    return max;
}

int find_max_index(const std::vector<int> &counts)
{
    int max_index = 0;
    int max = 0;
    for (int idx=0; idx<(ASCI_END-ASCI_START);idx++)
    {
        if (counts[idx]>max)
        {
            max = counts[idx];
            max_index = idx;
        }
    }

    return max_index;
}




void parse_input(std::vector<int> &counts)
{
    char buf[DEFAULT_BUF_LENGTH];
    int char_as_int;

    while (true)
    {   
        std::cin.read(buf, DEFAULT_BUF_LENGTH);
        int size = std::cin.gcount();
        if (size == 0) break;

        for(int idx=0;idx<size;idx++)
        {   
            char_as_int = buf[idx];
            counts[char_as_int-ASCI_START]++;
        }
    }
}