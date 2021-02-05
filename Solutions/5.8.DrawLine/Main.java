/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
    public static void drawLine(byte screen[], int w, int x1, int x2, int y){
        if(x1==x2 || x1>w || x2>w)
            return;
        int x1BytePos=x1/8+((w/8)*y);
        int x1BitPos=x1%8;
        int x2BytePos=x2/8+((w/8)*y);
        int x2BitPos=x2%8;
        int mask=0xFF;
        int temp;
        if(x1BytePos==x2BytePos){
            mask=mask>>(7-x2BitPos);
            mask=mask<<(31-x2BitPos+x1BitPos);
            mask=mask>>>(24+x1BitPos);
          
            
            
            temp=screen[x1BytePos] | (byte)(mask);
            screen[x1BytePos]=(byte)(temp);
        }
        else{
            mask=mask>>x1BitPos;
            temp=screen[x1BytePos] | (byte)(mask);
            screen[x1BytePos]=(byte)(temp);
            
            mask=0xFF;
            for(int i= x1BytePos+1;i<x2BytePos;i++){
                screen[i]=(byte)0xFF;
            }
            mask=mask<<(7- x2BitPos);
            temp=screen[x2BytePos] | (byte)(mask);
            screen[x2BytePos]=(byte)(temp);
        }
    }
    private static void printScreen(byte[] screen, int width) {
        int num = 1, widthNum = width/8;
        for (byte b : screen) {
            for (int i = 7; i >= 0; --i) {
                System.out.print((b >> i) & 1);
                
            }
            if (num % widthNum == 0) System.out.println();
            ++num;
        }
        System.out.println();
    }
    private static void print(int a) {
        int b;
        for(int i=31;i>=0;i--)
        {
             b= ((a & (1<<i))!=0)?1:0;
            System.out.print(b);
        }
        System.out.println();
    }
	public static void main(String[] args) {
        byte screen[]=new byte[16] ;
        int w=32;
        int x1=9;
        int x2=30;
        int y=2;
        printScreen(screen,w);
        drawLine(screen, w, x1, x2, y);
        printScreen(screen,w);
        
	}
}
