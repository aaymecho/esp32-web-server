import './index.css';
import { useState, useEffect } from 'react';

const apiUrl = import.meta.env.ESP32_API;


function App() {
  const [led4State, setLed4State] = useState<boolean>(false);
  const [led5State, setLed5State] = useState<boolean>(false);

  // Fetch the initial state of the LEDs
  useEffect(() => {
    const fetchInitialStates = async () => {
      try {
        const response4 = await fetch('http://192.168.1.29/led/4/status');
        const state4 = await response4.text();
        setLed4State(state4.trim() === 'ON');

        const response5 = await fetch('http://192.168.1.29/led/5/status');
        const state5 = await response5.text();
        setLed5State(state5.trim() === 'ON');
      } catch (error) {
        console.error('Error fetching initial states:', error);
      }
    };

    fetchInitialStates();
  }, []);

  const toggleLED = async (led: number, currentState: boolean) => {
    const newState = !currentState;
    const url = `http://192.168.1.29/led/${led}/${newState ? 'on' : 'off'}`;

    try {
      const response = await fetch(url);
      if (response.ok) {
        if (led === 4) {
          setLed4State(newState);
        } else if (led === 5) {
          setLed5State(newState);
        }
      } else {
        console.error('Failed to toggle LED');
      }
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <div className="min-h-screen bg-gray-100 flex flex-col items-center justify-center">
      <h1 className="text-3xl font-bold mb-8">LED Control</h1>
      <div className="space-y-4">
        <button
          className="bg-blue-500 text-white py-2 px-4 rounded shadow"
          onClick={() => toggleLED(4, led4State)}
        >
          Toggle LED 4 (Currently {led4State ? 'ON' : 'OFF'})
        </button>
        <button
          className="bg-green-500 text-white py-2 px-4 rounded shadow"
          onClick={() => toggleLED(5, led5State)}
        >
          Toggle LED 5 (Currently {led5State ? 'ON' : 'OFF'})
        </button>
      </div>
    </div>
  );
}

export default App;
