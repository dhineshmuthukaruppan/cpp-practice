#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */


class Rectangle{
    protected:
        int width; 
        int height; 

    public:
        virtual void display(){
            cout << width << " " << height << endl; 
        }; 


}; /* end of Rectangle */

class RectangleArea : public Rectangle{

    public:
        void read_input(){
            cin >> width >> height; 
        }

        virtual void display() override{
            cout << width*height << endl; 

        }


};  /* end of RectangleArea */



int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}