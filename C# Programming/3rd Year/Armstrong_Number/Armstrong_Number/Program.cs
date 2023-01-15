/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 3-1N
* 3-Digit Armstrong Number
*/

using System;

namespace Armstrong_Number{
    internal class Program{
        static void Main(string[] args){

            int num, r, sum = 0, temp;

            Console.WriteLine("===== 3-DIGIT ARMSTRONG NUMBER =====\n");

            while (true){
                Console.Write("Enter a number: ");

                try{
                    num = int.Parse(Console.ReadLine());

                    if (num < 0 || num > 999){
                        Console.WriteLine("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                        Console.WriteLine("  Positive Integers (0 - 999) only.   ");
                        Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    }
                    else{
                        temp = num;

                        while (num > 0){
                            r = num % 10;
                            sum += (r * r * r);
                            num /= 10;
                        }

                        Console.WriteLine("\n====================================");

                        if (temp == sum)
                            Console.WriteLine("    " + temp + " is an Armstrong Number");
                        else
                            Console.WriteLine("    " + temp + " is Not Armstrong Number");

                        Console.WriteLine("====================================");

                        break;
                    }
                }catch (Exception e){
                    Console.WriteLine("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                    Console.WriteLine("        Positive Integers only.       ");
                    Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                }
            }
        }
    }
}
