// showing the number of items and the percentage
export default function Stats({ items }) {
  // if there are no items then it displays the start packing message
  if (!items.length)
    return (
      <p className="stats">
        <em>Start adding some items to your packing list 🚀</em>
      </p>
    );

  // to display the number of items
  const numItems = items.length;
  // counting the num items that are checked off (packed)
  const numPacked = items.filter((item) => item.packed).length;
  // showing the percentage packed
  const percentage = Math.round((numPacked / numItems) * 100);

  return (
    <footer className="stats">
      <em>
        {/* conditional so if everything is packed (100%) then it will display the ready to go  */}
        {percentage === 100
          ? "You got everything! Ready to go! ✈️"
          : `🧳 You have ${numItems} items on your list, and you already packed
        ${numPacked} (${percentage}%)`}
      </em>
    </footer>
  );
}
