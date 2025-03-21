import React from "react";

interface Props {
  name: string;
}

const Greeting: React.FC<Props> = ({ name }) => {
  return <h1>Hello, {name}! Welcome to TypeScript with React. 🚀</h1>;
};

export default Greeting;
