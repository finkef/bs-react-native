let make:
  (
    ~values: list(string),
    ~selectedIndex: int=?,
    ~onChange: RNEvent.t => unit=?,
    ~enabled: bool=?,
    ~momentary: bool=?,
    ~tintColor: string=?,
    ~onValueChange: string => unit=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `none
                              | `button
                              | `link
                              | `header
                              | `search
                              | `image
                              | `selected
                              | `plays
                              | `key
                              | `text
                              | `summary
                              | `disabled
                              | `frequentUpdates
                              | `startsMedia
                              | `adjustable
                              | `allowsDirectInteraction
                              | `pageTurn
                            ]
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
