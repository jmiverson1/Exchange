using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Collections;

namespace TCP_Test
{
    class TCPClient
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            TCPClient client = null;
            client = new TCPClient("CSC559TestFile1.txt\r\n");
            client = new TCPClient("CSC559TestFile2.txt\r\n");
            client = new TCPClient("CSC559TestFile3.txt\r\n");
            client = new TCPClient("CSC559TestFile4.txt\r\n");
            client = new TCPClient("CSC559TestFile5.txt\r\n");
            client = new TCPClient("CSC559TestFile6.txt\r\n");
        }

        private String m_fileName = null;
        public TCPClient(String fileName)
        {
            m_fileName = fileName;
            Thread t = new Thread(new ThreadStart(ClientThreadStart));
            t.Start();
        }

        private void ClientThreadStart()
        {
            Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            clientSocket.Connect(new IPEndPoint(IPAddress.Loopback, 1000));

            // Send the file name.
            clientSocket.Send(Encoding.ASCII.GetBytes(m_fileName));

            // Receive the length of the filename.
            byte[] data = new byte[128];
            clientSocket.Receive(data);
            int length = BitConverter.ToInt32(data, 0);

            clientSocket.Send(Encoding.ASCII.GetBytes(m_fileName + ":" + "the TCPClient is sending data to the TCPServerService\r\n"));

            clientSocket.Send(Encoding.ASCII.GetBytes(m_fileName + ":" + "test message"));
            clientSocket.Send(Encoding.ASCII.GetBytes("test message"));
            clientSocket.Send(Encoding.ASCII.GetBytes("test message."));
            clientSocket.Send(Encoding.ASCII.GetBytes("\r\n"));
            clientSocket.Send(Encoding.ASCII.GetBytes(m_fileName + ":" + "TEST.\r\n" + m_fileName + ":" + "TEST AGAIN.\r\n"));
            clientSocket.Send(Encoding.ASCII.GetBytes("[EOF]\r\n"));

            // Get the total length
            clientSocket.Receive(data);
            length = BitConverter.ToInt32(data, 0);
            clientSocket.Close();
        }

    }
}
