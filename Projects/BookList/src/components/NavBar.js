import React, { useContext } from 'react';
import { BookContext } from '../contexts/BookContext';

const NavBar = () => {
    const { books } = useContext(BookContext);
    return (
        <div className="navbar">
            <h1>Book Store</h1>
            <p>Currently we have {books.length} Books in our Store.</p>
        </div>
    );
}

export default NavBar;