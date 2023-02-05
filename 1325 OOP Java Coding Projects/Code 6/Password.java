/*
 * Ahmed Ibrahim 1001820005
 */
package code6_1001820005;
import javax.swing.JPasswordField;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JOptionPane;
public class Password extends JFrame
{
    private final JPasswordField passwordField;
    private String entered_password;
    private final String actual_password = "hi";
    
    public Password()
    {
        super("Password Field");
        setLayout(new FlowLayout());
        passwordField = new JPasswordField(20);
        passwordField.setEchoChar('x');
        add(passwordField);
        EventHandler handler = new EventHandler();
        passwordField.addActionListener(handler);
    }
    
    private class EventHandler implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            if(event.getSource()==passwordField)
            {
                entered_password = event.getActionCommand();
                
            }
            if(entered_password.equals(actual_password))
            {
                setVisible(false);
                GameFrame gameframe = new GameFrame();
                gameframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                gameframe.setSize(500,500);
                gameframe.setVisible(true);
            }
            else
            {
                JOptionPane.showMessageDialog(null, "Incorrect Password");
            }
        }
    }
}