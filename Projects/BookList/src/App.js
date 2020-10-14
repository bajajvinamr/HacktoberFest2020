import React from 'react';
import BookContextProvider from './contexts/BookContext';
import NavBar from './components/NavBar';
import BookList from './components/BookList';
import NewBookForm from './components/NewBookForm';

function App() {
  return (
    <div className="App">
      <BookContextProvider>
        <NavBar />
        <BookList />
        <NewBookForm />
      </BookContextProvider>
    </div>
  );
}

export default App;
