/*
* Group 1: Besmonte, Gozum, Mendoza, Sison, Suzn
* BSCS 2-5
* Horoscope
*/

import javax.swing.*;

public class Assign3_5 
{
    static JComboBox c1,c2,c3;
    static String cmonth, cday, cyear;
    static  String months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                                "September", "October", "November", "December"}; 
    static String days[], years[];

    public static void main(String[] args)
    {   
        days = new String[31];
        years = new String[32];

        //Initialized day list
        for(int i=1; i<=31; i++)
        {
            days[i-1] = String.valueOf(i);
        }

        //Initialized year list
        for(int i=1990; i<=2021; i++)
        {
            years[i-1990] = String.valueOf(i);
        }

        //Create Box Inputs
        c1 = new JComboBox<>(months);
        c2 = new JComboBox<>(days);
        c3 = new JComboBox<>(years);
        
        //Asks user for inputs
        JPanel p = new JPanel();
        JOptionPane.showMessageDialog(null, c1, "Birth Month", JOptionPane.QUESTION_MESSAGE);
        JOptionPane.showMessageDialog(null, c2, "Birth Day", JOptionPane.QUESTION_MESSAGE);
        JOptionPane.showMessageDialog(null, c3, "Birth year", JOptionPane.QUESTION_MESSAGE);
        p.add(c1);
        p.add(c2);
        p.add(c3);

        //Store user inputs
        cmonth = c1.getSelectedItem().toString();
        cday = c2.getSelectedItem().toString();
        cyear = c3.getSelectedItem().toString();
        result();
    }

    public static void result()
    {
        String text="";
        int m=0, d=0, y=0;

        //Converts string input from combo boxes to int
        for(int i=0; i<12; i++)
        {
            if(months[i].equals(cmonth))
            {
                m = i+1;
                break;
            }
        }
        d = Integer.parseInt(cday);
        y = Integer.parseInt(cyear);

        //Gets Zodiac Sign and Horoscope 
        if((m == 1 && d >= 20 && y >= 0000) || (m == 2 && d <= 17 && y >= 0000))
        {
            text = "ZODIAC SIGN: Aquarius\n\n"+
            "HOROSCOPE: It is easy to get impatient with those who don't think or act as fast as "+
            "you do, but if you are smart you will make allowances for lesser mortals and give them "+
            "lots of encouragement rather than criticism. Build them up, don't knock them down.";
        }

        else if((m == 2 && d >= 18 && y >= 0000) || (m == 3 && d <= 19 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Pisces\n\n"+
        	"HOROSCOPE: Nothing in life stays the same for long and it is important that "+
        	"you recognize and accept that truth today."+
        	"The good news is that what changes over the next few days will create opportunities "+
        	"that you are well placed to take advantage of.";
        }

        else if((m == 3 && d >= 20 && y >= 0000) || (m == 4 && d <= 19 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Aries\n\n"+
                	"HOROSCOPE: Try to lighten up a bit today."+
                	"The approaching solar eclipse is sure to present you with at least one, and maybe several,"+
                	"opportunities to enrich yourself, so there is no need to be uptight. "+
                	"Life is good and getting better by the minute, so be happy.";
         }

        else if((m == 4 && d >= 20 && y >= 0000) || (m == 5 && d <= 20 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Taurus\n\n"+
                	"HOROSCOPE: Do not try to avoid a tough decision of some kind. "+
                    "Cosmic activity in the wealth area of your chart means there could be a lot of money at stake, "+
                	"so the choices you make will be of huge importance, not just for you but for other people too.";
        }        	
        
        else if((m == 5 && d >= 21 && y >= 0000) || (m == 6 && d <= 20 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Gemini\n\n"+
                	"HOROSCOPE: Reach out to others and get them to join you in whatever creative activity you are enjoying. "+
                    "You will be able to do a lot on \\nyour own over the next few days, but you will do "+
                    "much more if you bring like-minded people onto your team.";
                	
        }

        else if((m == 6 && d >= 21 && y >= 0000) || (m == 7 && d <= 22 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Cancer\n\n"+
                	"HOROSCOPE: As a cardinal sign you enjoy a challenge and that is just as well because tomorrow's "+
                	"eclipse will in some way or other put you on the spot regarding your work. "+
                    "Make sure others can see you are serious about doing the best possible job that you can.";
                    
        }

        else if((m == 7 && d >= 23 && y >= 0000) || (m == 8 && d <= 22 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Leo\n\n"+
                	"HOROSCOPE: Try to be a bit more open-minded and light-hearted today. "+
                	"The Sun in the most dynamic area of your chart at this time of year "+
                	"encourages you to believe that all things are possible, and they are, "+
                	"but the right attitude is essential both at home and at work.";
                    
                    
        }

        else if((m == 8 && d >= 23 && y >= 0000) || (m == 9 && d <= 22 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Virgo\n\n"+
                	"HOROSCOPE: The most important thing now is that you stand your ground and don't give in to either threats or bribes."+
                	"The more pressure others \\nput you under today and over the weekend "+
                	"the less likely it is their proposals will benefit you in any big way.";
                    
        }

        else if((m == 9 && d >= 23 && y >= 0000) || (m == 10 && d <= 22 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Libra\n\n"+
                	"HOROSCOPE: By all means be assertive today but don't forget that other people have feelings "+
                	"and respond better to persuasion than to coercion."+
                	"Let them know what it is you want from them but say it with a smile rather than a snarl. "+
                	"You'll get more cooperation that way.";
        }

        else if((m == 10 && d >= 23 && y >= 0000) || (m == 11 && d <= 21 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Scorpio\n\n"+
                	"HOROSCOPE: There is a ruthless side to the Scorpio nature that for the most part you keep well hidden, "+
                	"but what occurs today means you cannot afford to pretend to be nice."+
                	"Friendship is important, of course, but on this occasion friendship comes second to getting things done!";
        }

        else if((m == 11 && d >= 22 && y >= 0000) || (m == 12 && d <= 21 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Sagittarius\n\n"+
                	"HOROSCOPE: Tomorrows solar eclipse means the cosmic powers are very much on your side, so put a name to "+
                	"your dream and go after it with 100 per cent commitment and 100 percent self-belief. "+
                	"If you want to win you will win, it Is as simple as that.";
                	
        }

        else if((m == 12 && d >= 22 && y >= 0000) || (m == 1 && d <= 19 && y >= 0000))
        {
        	text = "ZODIAC SIGN: Capricorn\n\n"+
                	"HOROSCOPE: You seem to believe that someone has got you in their sights "+
                	"and is waiting for the right moment to bring you down."+
                	"That may be true but more likely you are allowing unfounded fears to get the better of you. "+
                	"Who would dare take you on?";
                	
        }

        //Displays output
        JTextArea textArea = new JTextArea(text);
        textArea.setColumns(30);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setSize(textArea.getPreferredSize().width, 1);
        JOptionPane.showMessageDialog(null, new JScrollPane( textArea), "Results",
        JOptionPane.INFORMATION_MESSAGE);
    }
}  