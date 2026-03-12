import React, { useState } from 'react';
import Login from './components/Auth/Login';
import Signup from './components/Auth/Signup';
import Home from './components/Home';

function App() {
  const [currentView, setCurrentView] = useState('login');
  const [user, setUser] = useState(null);
  const [showProfile, setShowProfile] = useState(false);

  const handleLogin = (formData) => {
    setUser({ name: 'User', email: formData.email });
    setCurrentView('home');
  };

  const handleSignup = (formData) => {
    setUser({ name: formData.name, email: formData.email });
    setCurrentView('home');
  };

  const handleLogout = () => {
    setUser(null);
    setCurrentView('login');
    setShowProfile(false);
  };

  return (
    <div className="app">
      {currentView === 'login' && (
        <Login 
          onLogin={handleLogin}
          switchToSignup={() => setCurrentView('signup')}
        />
      )}
      {currentView === 'signup' && (
        <Signup 
          onSignup={handleSignup}
          switchToLogin={() => setCurrentView('login')}
        />
      )}
      {currentView === 'home' && (
        <Home 
          user={user}
          onLogout={handleLogout}
          showProfile={showProfile}
          setShowProfile={setShowProfile}
        />
      )}
    </div>
  );
}

export default App;