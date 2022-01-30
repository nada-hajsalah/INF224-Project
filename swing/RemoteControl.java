import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;
import java.awt.Color;
/**
 * @brief RemoteControl
 */


public class RemoteControl extends JFrame
{
        private static final long serialVersionUID = 1L;
        /** Contains input to be sent throught sockets */
        private static JTextField textField;
        /** Contains result fetched from socket */
        private static JTextArea textArea;

        private Client client;

        public RemoteControl(Client client) {
                this.client = client;
        }
        /**  Display the buttons, the textArea and the textField*/
        public void display() {

                addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                                System.exit(0);
                        }
                });

                textArea = new JTextArea(29, 29);
                textField = new JTextField("");

                textField.setColumns(29);

                JScrollPane scrollPane = new JScrollPane(textArea);
                JToolBar tbar = new JToolBar();
                JPanel panel = new JPanel();

                SearchAction searchAction = new SearchAction("Search");

                GroupAction groupAction = new GroupAction("Search Group");

                PlayAction playAction = new PlayAction("Play");

                CloseAction closeAction = new CloseAction("Close");

                JButton searchButton = new JButton(searchAction);

                JButton groupButton = new JButton(groupAction);
                JButton playButton = new JButton(playAction);
                JButton closeButton = new JButton(closeAction);
                /** To color the button */
                closeButton.setBackground(Color.red);
                playButton.setBackground(Color.green);
                groupButton.setBackground(Color.PINK.darker());
                searchButton.setBackground(Color.PINK.darker());

                JMenuBar menub = new JMenuBar();
                JMenu menu = new JMenu("Menu");
                menu.add(new JMenuItem(searchAction));
                menu.add(new JMenuItem(playAction));
                menu.add(new JMenuItem(groupAction));
                menu.add(new JMenuItem(closeAction));

                menu.add(menub);

                setJMenuBar(menub);

                searchButton.setPreferredSize(new Dimension(99, 29));
                playButton.setPreferredSize(new Dimension(99, 29));
                groupButton.setPreferredSize(new Dimension(99, 29));
                closeButton.setPreferredSize(new Dimension(99, 29));

                tbar.add(searchButton);
                tbar.add(groupButton);
                tbar.add(playButton);
                tbar.add(closeButton);

                tbar.add(textField);

                add(tbar, BorderLayout.NORTH);
                add(scrollPane, BorderLayout.SOUTH);

                pack();
                setVisible(true);
        }

        String parsing(String result) {
                String response = result.replace("**", "\n");
                return response;
        }

        /**
         * @brief send a Search request to the server and shows the result in textArea
         */
        class SearchAction extends AbstractAction {
                private static final long serialVersionUID = 201811031717L;
                public SearchAction(String name) {
                        super(name);
                }
                @Override
                public void actionPerformed(ActionEvent e) {
                        String response = client.send("Search " + textField.getText());
                        response = parsing(response);
                        textArea.append(response);
                }

        }

        /**
         *@brief send a Play request to the server and shows the result in textArea
         */

        class PlayAction extends AbstractAction {
                private static final long serialVersionUID = 201811031718L;
                public PlayAction(String name) {
                        super(name);
                }
                @Override
                public void actionPerformed(ActionEvent e) {
                        String response = client.send("Play " + textField.getText());
                        response = parsing(response);
                        textArea.append(response);
                }
        }
        /**
        * @brief send a Search for group request to the server and shows the result in textArea
        */

        class GroupAction extends AbstractAction {
                private static final long serialVersionUID = 201811031720L;
                public GroupAction(String name) {
                        super(name);
                }
                @Override
                public void actionPerformed(ActionEvent e) {
                        String response = client.send("Search_Group " + textField.getText());
                        response = parsing(response);
                        textArea.append(response);
                }
        }


        /**
        *@brief to  Close the execution
        */

        class CloseAction extends AbstractAction {
                private static final long serialVersionUID = 201811031719L;
                public CloseAction(String name) {
                        super(name);
                }
                @Override
                public void actionPerformed(ActionEvent e) {
                        System.exit(0);

                }
        }

}
