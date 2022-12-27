import java.util.*;
import javax.swing.*;

public class Prime_Composite 
{
    public static void main(String[] args)
    {
        int num=0, repeat=0, go=0, ans=0, first=0, count=0, isComposite=0;
        String input;
        LinkedList<Integer> factors = new LinkedList<Integer>();

        do
        {
            num=0;
            isComposite=0;
            count=0;
            first=0;
            repeat = 1;
            go=0;

            input = JOptionPane.showInputDialog(null, "INPUT A NUMBER: " , "Prime/Composite Function", JOptionPane.INFORMATION_MESSAGE);
            if(input == null)
            {
                break;
            }
            try
            {
                num = Integer.parseInt(input);
                ans = num;
                go = 1;
            }
            catch(Exception e)
            {
                repeat = 0;
                continue;
            }

            if(num < 0)
            {
                JOptionPane.showMessageDialog(null, "Prime Factorization doesn't allow integers less than 1", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                repeat = 0;
                continue;
            }

            else if(num == 0)
            {
                JOptionPane.showMessageDialog(null, "CATEGORY: NEITHER PRIME NOR COMPOSITE NUMBER\nFACTORS: " +0, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                go = 0;
            }

            if(go==1)
            {
                for(int i=1; i<num; i++)
                {
                    for(int j=1; j<num; j++)
                    {
                        if(first == 1 && j == 1)
                        {
                            continue;
                        }

                        else if(ans%j == 0)
                        {
                            first = 1;
                            ans = ans / j;
                            
                            factors.add(j);
                            count++;

                            if(count == 2)
                            {
                                isComposite=1;
                            }
                            break;
                        }
                    }
                }

                if(isComposite==1)
                {
                    JOptionPane.showMessageDialog(null, "CATEGORY: COMPOSITE NUMBER\nFACTORS: " +factors, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                }

                else
                {
                    JOptionPane.showMessageDialog(null, "CATEGORY: PRIME NUMBER\nFACTORS: " +factors, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                }
                
                for(int i=0; i<count; i++)
                {
                    factors.removeFirst();
                }
            }

            repeat = JOptionPane.showConfirmDialog(null, "Use this function again?", "Prime/Composite Function",
			JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);

        }
        while(repeat == 0);
    }
}
