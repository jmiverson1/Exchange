using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrderContainerTest
{
    class OrderContainer
    {
        object[] dataContainers;
        int ctr = 0;

        public OrderContainer(int orderCapacity)
        {
            dataContainers = new object[orderCapacity];
        }
        public void AddOrder(object order)
        {
            dataContainers[ctr] = order;
            ctr++;
        }
        public object GetOrder(int index)
        {
            return dataContainers[index];
        }
    }

    class NonGenericOrderContainer
    {
        public class OrderObj
        {
            public string Instrument;
            public double Quantity;
        }

        static void Main(string[] args)
        {
            OrderContainer orderObjContainer = new OrderContainer(10);
            orderObjContainer.AddOrder(new OrderObj() { Instrument = "Test", Quantity = 2 });
            OrderObj orderobj = orderObjContainer.GetOrder(0) as OrderObj;
            Console.Out.WriteLine("Order = " + orderobj.Instrument + "\nQuantity = " + orderobj.Quantity.ToString());
        }
    }
}
