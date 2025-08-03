local wezterm = require 'wezterm'
local config = wezterm.config_builder()

-- ========================================
-- TEMA FUTURISTA: CYBER DREAM
-- ========================================

config.colors = {
  -- Fondo ultra moderno con degradado
  background = '#0f0f23',
  foreground = '#00ff88',  -- Verde cibernético brillante
  
  -- Cursor neón pulsante
  cursor_bg = '#00ffcc',
  cursor_fg = '#0f0f23',
  cursor_border = '#00ffcc',
  
  -- Selección holográfica
  selection_bg = 'rgba(0, 255, 136, 0.3)',
  selection_fg = '#ffffff',
  
  scrollbar_thumb = '#1e293b',
  split = '#00ff88',
  
  -- Paleta cyberpunk vibrante
  ansi = {
    '#1e1e2e',  -- Negro profundo
    '#ff4466',  -- Rojo neón intenso
    '#00ff88',  -- Verde cibernético brillante
    '#ffee00',  -- Amarillo eléctrico puro
    '#00ccff',  -- Azul holográfico vibrante
    '#dd88ff',  -- Púrpura sintético brillante
    '#00ffcc',  -- Cian radiante
    '#ffffff',  -- Blanco cristalino
  },
  brights = {
    '#475569',  -- Gris metálico
    '#ff6688',  -- Rojo ultra brillante
    '#44ffaa',  -- Verde radiante
    '#ffff44',  -- Amarillo nuclear
    '#66ddff',  -- Azul eléctrico
    '#ffaaff',  -- Púrpura vibrante
    '#66ffee',  -- Cian luminoso
    '#ffffff',  -- Blanco puro
  },
  
  tab_bar = {
    background = '#0a0a0f',
    
    active_tab = {
      bg_color = '#00d9ff',
      fg_color = '#0f0f23',
      intensity = 'Bold',
    },
    
    inactive_tab = {
      bg_color = '#1a1a2e',
      fg_color = '#64748b',
    },
    
    inactive_tab_hover = {
      bg_color = '#2d3748',
      fg_color = '#00d9ff',
      italic = true,
    },
    
    new_tab = {
      bg_color = '#0a0a0f',
      fg_color = '#00d9ff',
    },
    
    new_tab_hover = {
      bg_color = '#7c3aed',
      fg_color = '#ffffff',
      intensity = 'Bold',
    },
  },
}

-- ========================================
-- FUENTES MEJORADAS
-- ========================================

config.font = wezterm.font_with_fallback {
  'Cascadia Code',
  'Consolas',
  'Courier New',
}

config.font_size = 12.0
config.line_height = 1.3
config.cell_width = 1.0

-- Habilitar ligaduras para código más elegante
config.harfbuzz_features = { 'calt=1', 'clig=1', 'liga=1' }

-- ========================================
-- VENTANA FUTURISTA CON EFECTOS
-- ========================================

config.window_decorations = "INTEGRATED_BUTTONS|RESIZE"

-- Transparencia avanzada
config.window_background_opacity = 0.88
config.text_background_opacity = 1.0

-- Gradiente cyberpunk épico
config.window_background_gradient = {
  colors = {
    '#0f0f23',
    '#1a0533',
    '#0f1419',
    '#0a0a0f',
  },
  orientation = { 
    Radial = { 
      cx = 0.8, 
      cy = 0.2, 
      radius = 1.5 
    } 
  },
  interpolation = 'CatmullRom',
  blend = 'Rgb',
}

-- Padding espacioso y elegante
config.window_padding = {
  left = 20,
  right = 20,
  top = 20,
  bottom = 20,
}

-- Marco personalizado
config.window_frame = {
  border_left_width = '0.5cell',
  border_right_width = '0.5cell',
  border_bottom_height = '0.25cell',
  border_top_height = '0.25cell',
  border_left_color = '#00d9ff',
  border_right_color = '#00d9ff',
  border_bottom_color = '#00d9ff',
  border_top_color = '#00d9ff',
}

-- Tamaño inicial perfecto
config.initial_cols = 110
config.initial_rows = 32

-- ========================================
-- PESTAÑAS CON ESTILO FUTURISTA
-- ========================================

config.tab_bar_at_bottom = false
config.use_fancy_tab_bar = true
config.hide_tab_bar_if_only_one_tab = false
config.tab_max_width = 30
config.show_new_tab_button_in_tab_bar = true

-- ========================================
-- CURSOR HOLOGRÁFICO
-- ========================================

config.default_cursor_style = 'BlinkingUnderline'
config.cursor_blink_rate = 700
config.cursor_thickness = '200%'

-- ========================================
-- EFECTOS VISUALES AVANZADOS
-- ========================================

config.scrollback_lines = 50000
config.enable_scroll_bar = true

-- Renderizado de alta calidad
config.front_end = "OpenGL"
config.max_fps = 60

-- Efectos de texto avanzados
config.freetype_load_flags = 'NO_HINTING'

-- ========================================
-- ATAJOS POWER USER
-- ========================================

config.keys = {
  -- === PESTAÑAS ===
  {
    key = 't',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.SpawnTab 'CurrentPaneDomain',
  },
  {
    key = 'w',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.CloseCurrentTab { confirm = false },
  },
  
  -- === APLICACIÓN ===
  {
    key = 'q',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.QuitApplication,
  },
  {
    key = 'F11',
    mods = '',
    action = wezterm.action.ToggleFullScreen,
  },
  
  -- === PANELES ===
  {
    key = 'Enter',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.SplitHorizontal { domain = 'CurrentPaneDomain' },
  },
  {
    key = '\\',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.SplitVertical { domain = 'CurrentPaneDomain' },
  },
  {
    key = 'x',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.CloseCurrentPane { confirm = false },
  },
  
  -- === NAVEGACIÓN ESTILO VIM ===
  {
    key = 'h',
    mods = 'CTRL|ALT',
    action = wezterm.action.ActivatePaneDirection 'Left',
  },
  {
    key = 'l',
    mods = 'CTRL|ALT',
    action = wezterm.action.ActivatePaneDirection 'Right',
  },
  {
    key = 'k',
    mods = 'CTRL|ALT',
    action = wezterm.action.ActivatePaneDirection 'Up',
  },
  {
    key = 'j',
    mods = 'CTRL|ALT',
    action = wezterm.action.ActivatePaneDirection 'Down',
  },
  
  -- === REDIMENSIONAR PANELES ===
  {
    key = 'LeftArrow',
    mods = 'CTRL|SHIFT|ALT',
    action = wezterm.action.AdjustPaneSize { 'Left', 3 },
  },
  {
    key = 'RightArrow',
    mods = 'CTRL|SHIFT|ALT',
    action = wezterm.action.AdjustPaneSize { 'Right', 3 },
  },
  {
    key = 'UpArrow',
    mods = 'CTRL|SHIFT|ALT',
    action = wezterm.action.AdjustPaneSize { 'Up', 3 },
  },
  {
    key = 'DownArrow',
    mods = 'CTRL|SHIFT|ALT',
    action = wezterm.action.AdjustPaneSize { 'Down', 3 },
  },
  
  -- === ZOOM ===
  {
    key = 'z',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.TogglePaneZoomState,
  },
  
  -- === FUENTE ===
  {
    key = '=',
    mods = 'CTRL',
    action = wezterm.action.IncreaseFontSize,
  },
  {
    key = '-',
    mods = 'CTRL',
    action = wezterm.action.DecreaseFontSize,
  },
  {
    key = '0',
    mods = 'CTRL',
    action = wezterm.action.ResetFontSize,
  },
  
  -- === PESTAÑAS NUMERADAS ===
  {
    key = '1',
    mods = 'ALT',
    action = wezterm.action.ActivateTab(0),
  },
  {
    key = '2',
    mods = 'ALT',
    action = wezterm.action.ActivateTab(1),
  },
  {
    key = '3',
    mods = 'ALT',
    action = wezterm.action.ActivateTab(2),
  },
  {
    key = '4',
    mods = 'ALT',
    action = wezterm.action.ActivateTab(3),
  },
  {
    key = '5',
    mods = 'ALT',
    action = wezterm.action.ActivateTab(4),
  },
  
  -- === EFECTOS ESPECIALES ===
  {
    key = 'r',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.ReloadConfiguration,
  },
  {
    key = 'p',
    mods = 'CTRL|SHIFT',
    action = wezterm.action.ActivateCommandPalette,
  },
}

-- ========================================
-- EVENTOS PERSONALIZADOS AVANZADOS
-- ========================================

-- Títulos de pestañas con íconos y efectos
wezterm.on(
  'format-tab-title',
  function(tab, tabs, panes, config, hover, max_width)
    local title = tab.tab_title
    if title and #title > 0 then
      title = title
    else
      title = tab.active_pane.title
    end
    
    -- Detectar tipo de shell/aplicación
    local process_name = tab.active_pane.foreground_process_name or ''
    local icon = '◉'
    local color_active = '#00d9ff'
    local color_inactive = '#64748b'
    
    if process_name:find('powershell') then
      icon = '⚡'
      color_active = '#00aaff'
    elseif process_name:find('cmd') then
      icon = '●'
      color_active = '#ffcc00'
    elseif process_name:find('git') then
      icon = '⬢'
      color_active = '#ff3366'
    elseif process_name:find('node') then
      icon = '◆'
      color_active = '#00ff88'
    elseif process_name:find('python') then
      icon = '◈'
      color_active = '#cc88ff'
    end
    
    -- Limpiar título
    title = title:gsub('Administrator: ', '')
    title = title:gsub('Windows PowerShell', 'PowerShell')
    title = title:gsub('Command Prompt', 'CMD')
    
    if #title > max_width - 6 then
      title = wezterm.truncate_right(title, max_width - 6) .. '…'
    end
    
    if tab.is_active then
      return {
        { Background = { Color = color_active } },
        { Foreground = { Color = '#0f0f23' } },
        { Attribute = { Intensity = 'Bold' } },
        { Text = ' ' .. icon .. ' ' },
        { Text = title },
        { Text = ' ' },
      }
    else
      return {
        { Background = { Color = '#1a1a2e' } },
        { Foreground = { Color = color_inactive } },
        { Text = ' ' .. icon .. ' ' },
        { Text = title },
        { Text = ' ' },
      }
    end
  end
)

-- Animación de bienvenida
wezterm.on('gui-startup', function()
  local tab, pane, window = wezterm.mux.spawn_window({})
  -- Centrar ventana sin maximizar
end)

-- ========================================
-- CONFIGURACIONES FINALES PREMIUM
-- ========================================

-- Audio y notificaciones
config.audible_bell = 'Disabled'
config.visual_bell = {
  fade_in_function = 'EaseIn',
  fade_in_duration_ms = 200,
  fade_out_function = 'EaseOut',
  fade_out_duration_ms = 200,
}

-- Comportamiento avanzado
config.automatically_reload_config = true
config.check_for_updates = true
config.show_update_window = false

-- Selección inteligente
config.selection_word_boundary = ' \t\n{}[]()"\'-+=;:.,?│┃┏┓┗┛┣┫┳┻╋╭╮╯╰'

-- Rendimiento optimizado
config.enable_kitty_graphics = true
config.enable_kitty_keyboard = true

-- Sin confirmaciones molestas
config.window_close_confirmation = 'NeverPrompt'
config.warn_about_missing_glyphs = false

-- Scrolling suave
config.alternate_buffer_wheel_scroll_speed = 5

return config