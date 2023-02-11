/*
 * Ahmed Ibrahim 1001820005
 */
package code6_1001820005;
import javax.swing.JTextField;
import java.util.Random;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import javax.swing.JOptionPane;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JButton;
public class GameFrame extends JFrame
{
    private final JLabel label1;
    private final JButton OKButton;
    private final JButton CancelButton;
    private final JTextField textField1;
    
    private String CCName = " ";
    public GameFrame()
    {
        super("Character's Guess");
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Random rn = new Random();
        Icon CC = null;
        
        
        switch(rn.nextInt(4)+1)
        {
            case 1:
                CCName = "Jon";
                CC = new ImageIcon(getClass().getResource(CCName + ".jpg"));
                break;
            case 2:
                CCName = "Daenerys";
                CC = new ImageIcon(getClass().getResource(CCName + ".png"));
                break;
            case 3:
                CCName = "Tyrion";
                CC = new ImageIcon(getClass().getResource(CCName + ".jpg"));
                break;
            case 4:  
                CCName = "Ned";
                CC = new ImageIcon(getClass().getResource(CCName + ".jpg"));
                break;
        }
        label1 = new JLabel();
        label1.setText("GOT Character name");
        label1.setIcon(CC);
        label1.setHorizontalTextPosition(SwingConstants.CENTER);
        label1.setVerticalTextPosition(SwingConstants.BOTTOM);
        label1.setToolTipText("first name only");
        add(label1);
        
        EventHandler handler = new EventHandler();
        
        textField1 = new JTextField("Enter this character's name", 15);
        textField1.selectAll();
        textField1.addActionListener(handler);
        add(textField1);
        
        OKButton = new JButton("OK");
        OKButton.addActionListener(handler);
        add(OKButton);
        
        CancelButton = new JButton("Cancel");
        CancelButton.addActionListener(handler);
        add(CancelButton);
    }
    private class EventHandler implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String response = " ";
            
            String guess;
            guess = textField1.getText();
            boolean result = false;
            if(CCName.equalsIgnoreCase(guess))
            {
                response = guess;
                result = true;
            }
            else if(!CCName.equalsIgnoreCase(guess))
            {
                response = guess;
            }
            
            if(event.getSource()==OKButton || event.getSource()==textField1)
            {
                JOptionPane.showMessageDialog(GameFrame.this, String.format(guess, event.getActionCommand()));
                if(result==true)
                {
                    System.exit(0);
                }
            }
            else if(event.getSource()==CancelButton)
            {
                System.exit(0);
            }
        }
    }
}