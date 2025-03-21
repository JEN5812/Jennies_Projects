// item itself
export default function Item({ item, onDeleteItem, onToggleItems }) {
  return (
    // showing the listed item
    <li>
      {/* creates the checkbox  */}
      <input
        type="checkbox"
        value={item.packed}
        onChange={() => onToggleItems(item.id)}
      />
      {/* instead of using if statement we are using '?' just to see if packed = true  */}
      <span style={item.packed ? { textDecoration: "line-through" } : {}}>
        {item.quantity} {item.description}
      </span>
      {/* displaying remove button  */}
      {/* cannot use onDeleteItem by itself it needs an empty function in order to follow the click */}
      <button onClick={() => onDeleteItem(item.id)}>❌</button>
    </li>
  );
}
