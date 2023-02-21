import './App.css';
import { Navbar, Nav, Row, Col } from 'react-bootstrap';
import React from 'react';
import _cardOne from './components/cardOne';

const data = [
  { id: 1, username: "User 1", image: "https://via.placeholder.com/150x150" },
  { id: 2, username: "User 2", image: "https://via.placeholder.com/150x150" },
  { id: 3, username: "User 3", image: "https://via.placeholder.com/150x150" },
  { id: 4, username: "User 4", image: "https://via.placeholder.com/150x150" },
  { id: 5, username: "User 5", image: "https://via.placeholder.com/150x150" },
  { id: 6, username: "User 6", image: "https://via.placeholder.com/150x150" },
];

function App() {
  return (
    <div>
    
      <Navbar style={{display: "flex", padding: "6px"}} bg="light" expand="lg">
        <Navbar.Brand href="#home">React-Bootstrap</Navbar.Brand>
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav className="mr-auto">
            <Nav.Link href="#home">Home</Nav.Link>
            <Nav.Link href="#link">Link</Nav.Link>
          </Nav>
        </Navbar.Collapse>
      </Navbar>
    
      
      <div style={{
      display: "flex",
      justifyContent: "center",
      alignItems: "center",  
      margin: "20px",
      padding: "20px"
      }}>
    
        <Row>
          {data.map((user) => (
            <Col xs={6} md={3} key={user.id}>
              <_cardOne user={user} />
            </Col>
          ))}
        </Row>

      </div>

    </div>
  );
}

export default App;
