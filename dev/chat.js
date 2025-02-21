const apiKey = 'YOUR_OPENAI_API_KEY'; // Replace with your OpenAI API key
const chatlog = document.getElementById('chatlog');

async function sendMessage() {
  const userInput = document.getElementById('userInput').value;
  if (!userInput) return;

  // Add user message to chatlog
  chatlog.innerHTML += `<div><strong>You:</strong> ${userInput}</div>`;

  // Call OpenAI API
  const response = await fetch('https://api.openai.com/v1/chat/completions', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${apiKey}`
    },
    body: JSON.stringify({
      model: 'gpt-3.5-turbo',
      messages: [{ role: 'user', content: userInput }]
    })
  });

  const data = await response.json();
  const botReply = data.choices[0].message.content;

  // Add bot reply to chatlog
  chatlog.innerHTML += `<div><strong>Bot:</strong> ${botReply}</div>`;
  document.getElementById('userInput').value = ''; // Clear input field
}
const apiKey = 'YOUR_HUGGING_FACE_API_KEY'; // Replace with your API key
const model = 'gpt2'; // You can use other models like 'EleutherAI/gpt-neo-2.7B'

async function sendMessage() {
  const userInput = document.getElementById('userInput').value;
  if (!userInput) return;

  const response = await fetch(`https://api-inference.huggingface.co/models/${model}`, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${apiKey}`
    },
    body: JSON.stringify({
      inputs: userInput
    })
  });

  const data = await response.json();
  const botReply = data[0].generated_text;

  // Display bot reply
  document.getElementById('chatlog').innerHTML += `<div><strong>Bot:</strong> ${botReply}</div>`;
}