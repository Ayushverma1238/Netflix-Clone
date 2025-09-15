import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import App from './App.jsx'
import { HistoryProvider } from './context/HistoryContext.jsx'

createRoot(document.getElementById('root')).render(
  <HistoryProvider>
    <StrictMode>
      <App />
    </StrictMode>,
  </HistoryProvider>

)
