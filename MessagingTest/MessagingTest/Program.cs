using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Messaging;

namespace MessagingTest
{
    class Program
    {
        static void Main(string[] args)
        {
            if (!MessageQueue.Exists(@".\Private$\Test")) { MessageQueue.Create(@".\Private$\Test"); }
            MessageQueue msgQ = new MessageQueue(@".\Private$\Test", true);
            Message msg = new Message();
            Message msg1 = new Message();
            int i;
            Message[] allmsg = new Message[20];

            msgQ.Formatter = new XmlMessageFormatter(new Type[] { typeof(string) }); 

            msg.Body = "Sample message text.";
            msg.UseJournalQueue = true;
            msg.AttachSenderId = true;
            msg.Recoverable = true;

            msg1.Body = "Sample message text1.";
            msg1.UseJournalQueue = true;
            msg1.AttachSenderId = true;
            msg1.Recoverable = true;
            
            msgQ.Send(msg);
            msgQ.Send(msg1);
            msgQ.DefaultPropertiesToSend.UseJournalQueue = true;
            allmsg = msgQ.GetAllMessages();
            for (i = 0; i < allmsg.Length; i++) { Console.Out.WriteLine(string.Format("Pre-Receive Message Body {0}: {1}", i, allmsg[i].Body)); } 
            //for (i = 0; i < allmsg.Length; i++) { msgQ.Receive(); }
            allmsg = msgQ.GetAllMessages();
            for (i = 0; i < allmsg.Length; i++) { Console.Out.WriteLine(string.Format("Message Body {0}: {1}", i, allmsg[i].Body)); }
            msgQ.Close();
        }
    }
}
