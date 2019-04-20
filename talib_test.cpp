#include <iostream>
#include <time.h>
#include <assert.h>
#include "ta_libc.h"
using namespace std;

int main()
{
    cout << "ta-lib test" << endl;

    // init ta-lib context
    TA_RetCode retcode;
    retcode = TA_Initialize();
    assert(retcode == TA_SUCCESS);

    // comput moving average price
    TA_Real    close_price_array[100] = { 0 };
    // construct random price
    srand((unsigned)time(0));
    for (int i = 0; i < 100; i++)
        close_price_array[i] = rand() % 50 + 100;

    TA_Real    out[100] = { 0 };
    TA_Integer out_begin =0 ;
    TA_Integer out_nb_element=0  ;

    retcode = TA_MA(0, 99,
        &close_price_array[0],
        3, TA_MAType_SMA,
        &out_begin, &out_nb_element, &out[0]);

    assert(retcode == TA_SUCCESS);

    cout << "---- compute output ----" << endl;
    cout << "out_begin_index: " << out_begin << endl;
    cout << "out_nb_element: " << out_nb_element << endl;
    cout << "out price array: " << endl;
    
    /* The output isdisplayed here */
    int i;
    for( i=0; i <out_nb_element; i++ )
       printf( "%d = %f\n", out_begin+i,out[i] );
   
    printf( "%d = %f\n", out_begin+out_nb_element-1,out[out_nb_element-1]); //last record
    
    for (auto &price : close_price_array)
        cout << price << " ";
    cout<<endl<<endl;
       
    for (auto &price : out)
        cout << price << " ";
    
    

    retcode = TA_Shutdown();
    assert(retcode == TA_SUCCESS);

    return 0;
}
