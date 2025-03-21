import { useState } from "react";

// able to submit text but does not show yet
export default function Form({ onAddItems }) {
  const [description, setDescription] = useState("");
  const [quantity, setQuantity] = useState(1);

  function handleSubmit(e) {
    e.preventDefault();

    // safety net of not accepting a blank item
    if (!description) return;

    const newItem = { description, quantity, packed: false, id: Date.now() };
    console.log(newItem);

    onAddItems(newItem);

    // returns to initial state after something is submitted
    setDescription("");
    setQuantity(1);
  }

  return (
    // form section itself
    <form className="add-form" onSubmit={handleSubmit}>
      <h3>What do you need for your 😍 trip?</h3>
      <select
        value={quantity}
        // we use number to show as an actual number in the components
        onChange={(e) => setQuantity(Number(e.target.value))}
      >
        {/* automatically makes it from 1-20 */}
        {Array.from({ length: 20 }, (_, i) => i + 1).map((num) => (
          <option value={num} key={num}>
            {num}
          </option>
        ))}
      </select>
      {/* the text box for displaying the item to be added  */}
      <input
        type="text"
        placeholder="Item..."
        value={description}
        // letting us type in the text box
        onChange={(e) => setDescription(e.target.value)}
      />
      {/* add button  */}
      <button>Add</button>
    </form>
  );
}
