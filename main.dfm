object MainForm: TMainForm
  Left = 202
  Top = 500
  Width = 696
  Height = 427
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 32
    Top = 40
    object Salir1: TMenuItem
      Caption = 'Salir'
      OnClick = Salir1Click
    end
    object NuevaPelota1: TMenuItem
      Caption = 'Nueva Pelota'
      OnClick = NuevaPelota1Click
    end
    object AvanzarMenu: TMenuItem
      Caption = 'Avanzar'
      ShortCut = 65
      OnClick = AvanzarMenuClick
    end
  end
end
