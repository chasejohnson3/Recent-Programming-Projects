using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace WindowsFormsApp2
{
    


    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //// is the device currenlty connected to any tags?
            //TagInformation[] tagInfos = device.GetTags();

            //// multiple NFC tags can be in the RF field of the device at any one time
            //// however PCSC based devices typically force there to only be one
            //if (tagInfos.Length > 0)
            //{
            //    Console.WriteLine("TAGS IN RF FIELD" + Environment.NewLine);

            //    foreach (TagInformation tagInfo in tagInfos)
            //    {
            //        NfcTagFound(device, tagInfo);
            //    }
            //}
            //else
            //{
            //    Console.WriteLine("NO TAGS IN RF FIELD" + Environment.NewLine);
            //    MessageBox.Show("Please hold the tag up to the device.");
            //}
            MessageBox.Show("Please hold the tag up to the device.");
            //ReadNdef(Device device, TagInformation tagInfo);

        }

        private void DateInput_TextChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            this.DateInput.Text = this.dateTimePicker1.Value.ToShortDateString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Are you sure you want to lock the tag?\n\nTHIS IS PERMANENT!!!\n" +
                "Only press 'Yes' if this is a final product.", "WARNING", MessageBoxButtons.YesNoCancel);
        }

        private void WriteButton_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Writing information to tag...", "Writing");
            this.progressBar1.Visible = true;
            this.timer1.Start();

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // CHANGE THIS TO LINE UP WITH THE PROGRESS OF WRITING TO THE TAG
            if (this.progressBar1.Value < 100)
            {
                this.progressBar1.Value += 10;
            }
            if (this.progressBar1.Value == 100)
            {
                this.timer1.Stop();
                MessageBox.Show("The progress bar has filled up.");
                this.progressBar1.Visible = false;
                
                
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
            Random randy = new Random();
            // Read in the lines from the text file as an array.
            string[] lines = System.IO.File.ReadAllLines(@"C:\Users\Chase Johnson\Documents\Visual Studio 2017\Projects\NFC Master\NFC Programmer\Test File.txt");
            
            // Puts a random number from the test file into the Lot Code text box.
            this.LotCodeInput.Text = lines[randy.Next(1, lines.Length)];
            
            

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }

}




