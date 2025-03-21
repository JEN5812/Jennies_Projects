import { useState } from "react";
import "./styles.css";

const faqs = [
  {
    title: "Where are these chairs assembled?",
    text: "Lorem ipsum dolor sit amet consectetur, adipisicing elit. Accusantium, quaerat temporibus quas dolore provident nisi ut aliquid ratione beatae sequi aspernatur veniam repellendus.",
  },
  {
    title: "How long do I have to return my chair?",
    text: "Pariatur recusandae dignissimos fuga voluptas unde optio nesciunt commodi beatae, explicabo natus.",
  },
  {
    title: "Do you ship to countries outside the EU?",
    text: "Excepturi velit laborum, perspiciatis nemo perferendis reiciendis aliquam possimus dolor sed! Dolore laborum ducimus veritatis facere molestias!",
  },
];

export default function App() {
  return (
    <div>
      <Accordion data={faqs} />
    </div>
  );
}

function Accordion({ data }) {
  // dealing with opening only one box at time
  const [curOpen, setCurOpen] = useState(null);

  return (
    <div className="accordion">
      {data.map((el, i) => (
        <AccordionItem
          // using the current status of the open box
          curOpen={curOpen}
          onOpen={setCurOpen}
          title={el.title}
          num={i}
          key={el.title}
        >
          {el.text}
        </AccordionItem>
      ))}
      <AccordionItem
        // using the current status of the open box
        curOpen={curOpen}
        onOpen={setCurOpen}
        title={"Test 1"}
        num={22}
        key={"test 1"}
      >
        <p>Allows React Developers to:</p>
        <ul>
          <li>Break up UI into components</li>
          <li>Make components reusuable </li>
          <li>Place state efficiently</li>
        </ul>
      </AccordionItem>
    </div>
  );
}

// this will only keep one box open at a time and cannot shrink the already open box
function AccordionItem({ num, title, curOpen, onOpen, children }) {
  const isOpen = num === curOpen;

  function handleToggle() {
    // opens the box + conditional for open/close the current box
    onOpen(isOpen ? null : num);
  }

  return (
    // coloring of the title
    <div className={`item ${isOpen ? "open" : ""}`} onClick={handleToggle}>
      {/* incrementing the bullet point numbers  */}
      <p className="number">{num < 9 ? `0${num + 1}` : num + 1}</p>
      <p className="title">{title}</p>
      {/* minus/plus sign toggle, when its open it is minus when it is closed it is plus  */}
      <p className="icon">{isOpen ? "-" : "+"}</p>

      {isOpen && <div className="content-box">{children}</div>}
    </div>
  );
}
