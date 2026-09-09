namespace led_turn_off
{
    public partial class MainPage : ContentPage
    {
        HttpClient client = new();

        public MainPage()
        {
            InitializeComponent();
        }

        async void redLed(object sender, ToggledEventArgs e)
        {
            if (e.Value)
                await client.GetAsync("http://IPonred");
            else
                await client.GetAsync("http://IP/offred");
        }

        async void greenLed(object sender, ToggledEventArgs e)
        {
            if (e.Value)
                await client.GetAsync("http://IP/ongreen");
            else
                await client.GetAsync("http://IP/offgreen");
        }

        async void blueLed(object sender, ToggledEventArgs e)
        {
            if (e.Value)
                await client.GetAsync("http://IP/onblue");
            else
                await client.GetAsync("http://IP/offblue");
        }
    }
}