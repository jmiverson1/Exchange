using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Dynamic;

namespace OrderBook
{
    public class Program
    {
        static void Main(string[] args)
        {
            Exchange CWF = new Exchange();
            Book Z5 = new Book("Z5", 1000, 1000);
            Book M6 = new Book("M6", 1000, 1000);
            CWF.addBook(Z5);
            CWF.addBook(M6);
            Trader BTR = new Trader("BTR", 10000.00, 0);
            Order buy0 = new Order(true, 1, "Z5", DateTime.Now, "BUYER0", 2.5);
            Order buy1 = new Order(true, 1, "Z5", DateTime.Now, "BUYER1", 2.5);
            Order buy2 = new Order(true, 3, "Z5", DateTime.Now, "BUYER2", 4.5);
            Order sell0 = new Order(false, 1, "Z5", DateTime.Now, "SELLER0", 2.5);
            Order sell1 = new Order(false, 1, "Z5", DateTime.Now, "SELLER1", 4.5);
            Order sell2 = new Order(false, 2, "Z5", DateTime.Now, "SELLER2", 4.5);
            Order sell7 = new Order(false, 1, "Z5", DateTime.Now, "SELLER2", 4.5);
            Order sell8 = new Order(false, 1, "Z5", DateTime.Now, "SELLER2", 4.5);
            Z5.addOrder(sell0);
            Z5.addOrder(sell1);
            Z5.addOrder(sell2);
            Z5.addOrder(sell7);
            Z5.addOrder(sell8);
            Z5.addOrder(buy0);
            Z5.addOrder(buy1);
            Z5.addOrder(buy2);
            Console.Out.WriteLine("Best Bid Price: " + Z5.bestBuy().Value.getPrice().ToString() + " Submitted at: " + Z5.bestBuy().Value.getDT().ToString("hh.mm.ss.ffffff")
                + " tradeID = " + Z5.bestBuy().Value.getOrderID().ToString());
            Console.Out.WriteLine("Best Offer Price: " + Z5.bestSell().Value.getPrice().ToString() + " Submitted at: " + Z5.bestSell().Value.getDT().ToString("hh.mm.ss.ffffff")
                + " tradeID = " + Z5.bestBuy().Value.getOrderID().ToString());
            Order buy3 = new Order(true, 1, "M6", DateTime.Now, "BUYER0" , 4.5);
            Order buy4 = new Order(true, 1, "M6", DateTime.Now, "BUYER1", 4.5);
            Order buy5 = new Order(true, 1, "M6", DateTime.Now, "BUYER2", 5.5);
            Order buy6 = new Order(true, 1, "M6", DateTime.Now, "BUYER2", 0);
            Order sell3 = new Order(false, 1, "M6", DateTime.Now, "SELLER0", 4.5);
            Order sell4 = new Order(false, 1, "M6", DateTime.Now, "SELLER1", 4.5);
            Order sell5 = new Order(false, 1, "M6", DateTime.Now, "SELLER2", 5.5);
            M6.addOrder(sell3);
            M6.addOrder(sell4);
            M6.addOrder(sell5);
            M6.addOrder(buy6);
            M6.addOrder(buy5);
            M6.addOrder(buy4);
            M6.addOrder(buy3);
            Console.Out.WriteLine("Best Bid Price: " + M6.bestBuy().Value.getPrice().ToString() + " Submitted at: " + M6.bestBuy().Value.getDT().ToString("hh.mm.ss.ffffff")
                + " tradeID = " + M6.bestBuy().Value.getOrderID().ToString());
            Console.Out.WriteLine("Best Offer Price: " + M6.bestSell().Value.getPrice().ToString() + " Submitted at: " + M6.bestSell().Value.getDT().ToString("hh.mm.ss.ffffff")
                + " tradeID = " + M6.bestBuy().Value.getOrderID().ToString());
            M6.cancelOrder(buy3);
            Order rec = processOrder("BTR1Z50010250");
            if (rec.creditCheck()) { CWF.getBook(rec.getExp()).addOrder(rec); } else { Console.Out.WriteLine("Order Rejected."); };
        }

        public static Order processOrder(string msg) 
        {
            char[] message = msg.ToCharArray();
            char[] concatID = new char[3];
            concatID[0] = message[0];
            concatID[1] = message[1];
            concatID[2] = message[2];
            string ID = new string(concatID);
            Console.Out.WriteLine("ID: " + ID);
            bool bs = Convert.ToBoolean(Convert.ToInt32(message[3]));
            Console.Out.WriteLine("BS: " + bs.ToString());
            char[] concatExp = new char[2];
            concatExp[0] = message[4];
            concatExp[1] = message[5];
            string exp = new string(concatExp);
            Console.Out.WriteLine("EXP " + exp);
            char[] concatQTY = new char[3];
            concatQTY[0] = message[6];
            concatQTY[1] = message[7];
            concatQTY[2] = message[8];
            int qty = Convert.ToInt32(new string(concatQTY));
            Console.Out.WriteLine("QTY: " + qty.ToString());
            char[] concatPR = new char[4];
            concatPR[0] = message[9];
            concatPR[1] = message[10];
            concatPR[2] = message[11];
            concatPR[3] = message[12];
            double price = Convert.ToDouble(new string(concatPR)) / 100;
            Console.Out.WriteLine("Price : " + price.ToString());

            return new Order(bs, qty, exp, DateTime.Now, ID, price);
        }

        static Hashtable MktPart = new Hashtable();

        public class Trader
        {
            string ID;
            double bal;
            int pos;

            public Trader(string ID, double bal, int pos) {
                this.ID = ID;
                this.bal = bal;
                this.pos = pos;
                MktPart.Add(this.ID, this);
            }

            public string getID() { return ID; }
            public double getBal() { return bal; }
            public int getPos() { return pos; }
            
            public void setBal(double newBal) { this.bal = newBal; }
            public void setPos(int newPos) { this.pos = newPos; }
        }
        
        public static int ID = 0;
        public static int orderID()
        {
            ID += 1;
            return ID;
        }
        
        public class Order
        {
            bool bs;
            int qty;
            double price;
            string exp;
            DateTime time;
            string ID;
            int orderID;
                        
            public Order(bool bs, int qty, string exp, DateTime time, string ID = "", double price = 0)
            {
                this.bs = bs;
                this.qty = qty;
                this.exp = exp;
                this.price = price;
                this.time = time;
                this.ID = ID;
                this.orderID = orderID();
            }

            public double getPrice() { return price; }
            public int getQty() { return qty; }
            public bool getBS() { return bs; }
            public string getExp() { return exp; }
            public DateTime getDT() { return time; }
            public string getID() { return ID; }
            public int getOrderID() { return orderID; }
            
            public void setQty(int newQty) { this.qty = newQty; }

            public bool creditCheck()
            {
                string newID = this.getID();
                Trader trdr = (Trader)MktPart[newID];
                if (trdr.getPos() < 0 && this.getBS() || trdr.getPos() > 0 && !(this.getBS()))
                {
                    trdr.setBal(trdr.getBal() + this.getQty() * 4.9);
                    trdr.setPos(trdr.getPos() - this.getQty());
                    Console.Out.WriteLine("Available Margin: " + trdr.getBal());
                    Console.Out.WriteLine("Current Position: " + trdr.getPos());
                    return true;
                }
                else
                {
                    if ((trdr.getBal() - this.getQty() * 4.9) > 0)
                    {
                        trdr.setBal(trdr.getBal() - this.getQty() * 4.9);
                        trdr.setPos(trdr.getPos() + this.getQty()*Convert.ToInt32(this.getBS()));
                        Console.Out.WriteLine("Available Margin: " + trdr.getBal());
                        Console.Out.WriteLine("Current Position: " + trdr.getPos());
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

        }

        public class Book
        {
            string contract;
            public LinkedList<Order>[] buys;
            public LinkedList<Order>[] sells;

            public Book(string contract, int buysize, int sellsize)
            {
                this.contract = contract;
                this.buys = new LinkedList<Order>[buysize];
                this.sells = new LinkedList<Order>[sellsize];
            }

            public string getContract() { return contract; }

            public void cancelOrder(Order delOrder)
            {
                if (delOrder.getBS())
                {
                    if (this.buys[Convert.ToInt32(delOrder.getPrice() / 0.01)].Find(delOrder).Next == null)
                    {
                        this.buys[Convert.ToInt32(delOrder.getPrice() / 0.01)].Remove(delOrder);
                        this.buys[Convert.ToInt32(delOrder.getPrice() / 0.01)].Clear();
                    }
                    else { this.buys[Convert.ToInt32(delOrder.getPrice() / 0.01)].Remove(delOrder); }
                }
                else
                {
                    if (this.sells[Convert.ToInt32(delOrder.getPrice() / 0.01)].Find(delOrder).Next == null)
                    {
                        this.sells[Convert.ToInt32(delOrder.getPrice() / 0.01)].Remove(delOrder);
                        this.sells[Convert.ToInt32(delOrder.getPrice() / 0.01)].Clear();
                    }
                    else { this.sells[Convert.ToInt32(delOrder.getPrice() / 0.01)].Remove(delOrder); }
                }
            }

            public void addOrder(Order newOrder)
            {
                if (newOrder.getBS())
                {
                    if (this.buys[Convert.ToInt32(newOrder.getPrice() / 0.01)] == null)
                    {
                        this.buys[Convert.ToInt32(newOrder.getPrice() / 0.01)] = new LinkedList<Order>();
                    }

                    if (this.bestSell() != null)
                    {
                        if (newOrder.getPrice() >= this.bestSell().Value.getPrice())
                        {
                            int remain = newOrder.getQty();
                            while (remain > 0)
                            {
                                int changeQty = Math.Min(remain, this.bestSell().Value.getQty());
                                Console.Out.WriteLine("Trade at: " + newOrder.getPrice().ToString() + " For " + changeQty);
                                newOrder.setQty(newOrder.getQty() - changeQty);
                                this.bestSell().Value.setQty(this.bestSell().Value.getQty() - changeQty);
                                if (this.bestSell().Value.getQty() == 0)
                                { this.cancelOrder(this.bestSell().Value); }
                                if (this.bestSell() == null) { break; }
                                remain = remain - changeQty;
                                Console.Out.WriteLine("Current trade remaining qty: " + remain);
                            }
                            if (newOrder.getQty() > 0) { this.buys[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                        }
                        else if (newOrder.getPrice() == 0.0)
                        {
                            int remain = newOrder.getQty();
                            while (remain > 0)
                            {
                                int changeQty = Math.Min(remain, this.bestSell().Value.getQty());
                                Console.Out.WriteLine("Market Order Trade at: " + this.bestSell().Value.getPrice().ToString() + " For " + changeQty);
                                newOrder.setQty(newOrder.getQty() - changeQty);
                                this.bestSell().Value.setQty(this.bestSell().Value.getQty() - changeQty);
                                if (this.bestSell().Value.getQty() == 0)
                                { this.cancelOrder(this.bestSell().Value); }
                                if (this.bestSell() == null) { break; }
                                remain = remain - changeQty;
                                Console.Out.WriteLine("Remaining qty: " + remain);
                            }
                            if (newOrder.getQty() > 0) { this.buys[Convert.ToInt32(this.bestBuy().Value.getPrice() / 0.01)].AddFirst(newOrder); }
                        }
                        else { this.buys[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                    }
                    else { this.buys[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                }
                else
                {
                    if (this.sells[Convert.ToInt32(newOrder.getPrice() / 0.01)] == null)
                    {
                        this.sells[Convert.ToInt32(newOrder.getPrice() / 0.01)] = new LinkedList<Order>();
                    }
                        if (this.bestBuy() != null)
                        {
                            if (newOrder.getPrice() >= this.bestBuy().Value.getPrice())
                            {
                                int remain = newOrder.getQty();
                                while (remain > 0)
                                {
                                    int changeQty = Math.Min(remain, this.bestBuy().Value.getQty());
                                    Console.Out.WriteLine("Trade at: " + newOrder.getPrice().ToString() + " For " + changeQty);
                                    newOrder.setQty(newOrder.getQty() - changeQty);
                                    this.bestBuy().Value.setQty(this.bestBuy().Value.getQty() - changeQty);
                                    if (this.bestBuy().Value.getQty() == 0)
                                    { this.cancelOrder(this.bestBuy().Value); }
                                    if (this.bestBuy() == null) { break; }
                                    remain = remain - changeQty;
                                    Console.Out.WriteLine("Current trade remaining qty: " + remain);
                                }
                                if (newOrder.getQty() > 0) { this.sells[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                            }
                            else if (newOrder.getPrice() == 0.0)
                            {
                                int remain = newOrder.getQty();
                                while (remain > 0)
                                {
                                    int changeQty = Math.Min(remain, this.bestBuy().Value.getQty());
                                    Console.Out.WriteLine("Market Order Trade at: " + this.bestBuy().Value.getPrice().ToString() + " For " + changeQty);
                                    newOrder.setQty(newOrder.getQty() - changeQty);
                                    this.bestBuy().Value.setQty(this.bestBuy().Value.getQty() - changeQty);
                                    if (this.bestBuy().Value.getQty() == 0)
                                    { this.cancelOrder(this.bestBuy().Value); }
                                    if (this.bestBuy() == null) { break; }
                                    remain = remain - changeQty;
                                    Console.Out.WriteLine("Remaining qty: " + remain);
                                }
                                if (newOrder.getQty() > 0) { this.sells[Convert.ToInt32(this.bestSell().Value.getPrice() / 0.01)].AddFirst(newOrder); }
                            }
                            else { this.sells[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                        }
                        else { this.sells[Convert.ToInt32(newOrder.getPrice() / 0.01)].AddLast(newOrder); }
                    }
                }
            

            public LinkedListNode<Order> bestBuy()
            {
                LinkedList<Order> best = null;
                for (int i = 0; i < 1000; i++) {
                    if (!(this.buys[i] == null)) {
                        if(this.buys[i].Count > 0) {
                            best = this.buys[i];
                        }
                    }
                }
                if (best == null) {
                    Console.Out.WriteLine("NULL BUY"); 
                    return null;
                }
                else { return best.First; }
            }

            public LinkedListNode<Order> bestSell()
            {
                LinkedList<Order> best = null;
                for (int i = 999; i > -1; i--) { 
                  if (!(this.sells[i] == null)) {
                    if (this.sells[i].Count > 0) {
                        best = this.sells[i];
                    }
                  }
                }
                if (best == null) {
                    Console.Out.WriteLine("NULL SELL");
                    return null; }
                else { return best.First; }
            }
        }

        public class Exchange
        {
            public Hashtable exch = new Hashtable();

            public Exchange() {}
                
            public void addBook(Book newBook) { exch.Add(newBook.getContract(), newBook); }
                
            public Book getBook(string contract) { return exch[contract] as Book; }
        }
    }
}
