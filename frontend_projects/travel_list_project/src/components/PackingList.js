import { useState } from "react";
import Item from "./Item";

// displaying the items
export default function PackingList({
  items,
  onDeleteItem,
  onToggleItems,
  onClearList,
}) {
  const [sortBy, setSortBy] = useState("input");

  // variable for using derived state
  let sortedItems;

  // sorting by input
  if (sortBy === "input") sortedItems = items;

  // sorted by alphabetical order
  if (sortBy === "description")
    sortedItems = items
      .slice()
      .sort((a, b) => a.description.localeCompare(b.description));

  // sorted with the checked off showing first
  if (sortBy === "packed")
    sortedItems = items
      .slice()
      .sort((a, b) => Number(a.packed - Number(b.packed)));

  return (
    <div className="list">
      {/* using unorganized list to display individual item  */}
      <ul>
        {sortedItems.map((item) => (
          <Item
            item={item}
            onDeleteItem={onDeleteItem}
            onToggleItems={onToggleItems}
            key={item.id}
          />
        ))}
      </ul>

      {/* action is the box that will be a dropdown menu  */}
      {/* the value is what lets it follow the functionality with sort by  */}
      <div className="actions">
        <select value={sortBy} onChange={(e) => setSortBy(e.target.value)}>
          <option value="input">Sort by input order</option>
          <option value="description">Sort by description</option>
          <option value="packed">Sort by packed status</option>
        </select>
        {/* using the onClearList function in order to clear list  */}
        <button onClick={onClearList}>Clear list</button>
      </div>
    </div>
  );
}
