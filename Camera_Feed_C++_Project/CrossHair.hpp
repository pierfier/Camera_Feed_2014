#ifndef CROSSHAIR_HPP
#define CROSSHAIR_HPP

public class CrossHair{
        
        //the value that determines the thinness of the cross hair
        int stroke;
        
        //the coordinate is dependent on whether the cross hair is
        //horizontal or vertical
        int coordinate;

        int width, height;

        //states whether 
        bool horizontal;

        void setHorizontal(){
                horizontal = true;
        }

        void setVertical(){
                horizontal = false;
        }

        void setCoordinate(int x){
                coordinate = x;
        }    

};
#endif
