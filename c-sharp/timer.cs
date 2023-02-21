using System;
using System.Windows.Forms;

public partial class Form1 : Form
    {
        private Timer timer;
        private int timeLeft;

        public Form1()
        {
            InitializeComponent();
            timeLeft = Convert.ToInt32(textBox1.Text);
        }

        private void StartButton_Click(object sender, EventArgs e)
        {
            timer = new Timer();
            timer.Interval = 1000;
            timer.Tick += Timer_Tick;
            timer.Start();
            StartButton.Enabled = false;
            StopButton.Enabled = true;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (timeLeft > 0)
            {
                timeLeft = timeLeft - 1;
                TimeLeftLabel.Text = timeLeft.ToString();
            }
            else
            {
                timer.Stop();
                TimeLeftLabel.Text = "Time's up!";
                StartButton.Enabled = true;
                StopButton.Enabled = false;
                MessageBox.Show("Time's up!");
            }
        }

        private void StopButton_Click(object sender, EventArgs e)
        {
            timer.Stop();
            StartButton.Enabled = true;
            StopButton.Enabled = false;
        }
    }
