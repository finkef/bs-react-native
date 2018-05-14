[@bs.module "react-native"] external view : ReasonReact.reactClass = "WebView";

type iOSLoadRequestEvent = {
  .
  "target": int,
  "canGoBack": bool,
  "lockIdentifier": int,
  "loading": bool,
  "title": string,
  "canGoForward": bool,
  "navigationType": string,
  "url": string
};

type source;

[@bs.obj]
external source :
  (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?, unit) => source =
  "";

type contentInsets;

[@bs.obj]
external contentInsets :
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) => contentInsets =
  "";

let make =
    (
      ~source=?,
      ~style=?,
      ~renderError=?,
      ~renderLoading=?,
      ~onError=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~automaticallyAdjustContentInsets=?,
      ~contentInsets=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
      ~injectJavaScript=?,
      ~injectedJavaScript=?,
      ~mediaPlaybackRequiresUserAction=?,
      ~onMessage=?,
      ~onNavigationStateChange=?,
      ~scalesPageToFit=?,
      ~startInLoadingState=?,
      ~domStorageEnabled=?,
      ~javaScriptEnabled=?,
      ~mixedContentMode=?,
      ~thirdPartyCookiesEnabled=?,
      ~userAgent=?,
      ~allowsInlineMediaPlayback=?,
      ~bounces=?,
      ~dataDetectorTypes=?,
      ~decelerationRate=?,
      ~onShouldStartLoadWithRequest=?,
      ~scrollEnabled=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        Props.extendView(
          ~accessibilityLabel?,
          ~accessible?,
          ~hitSlop?,
          ~onAccessibilityTap?,
          ~onLayout?,
          ~onMagicTap?,
          ~responderHandlers?,
          ~pointerEvents?,
          ~removeClippedSubviews?,
          ~style?,
          ~testID?,
          ~accessibilityComponentType?,
          ~accessibilityLiveRegion?,
          ~collapsable?,
          ~importantForAccessibility?,
          ~needsOffscreenAlphaCompositing?,
          ~renderToHardwareTextureAndroid?,
          ~accessibilityTraits?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
          {
            "source": from_opt(source),
            "style": from_opt(style),
            "automaticallyAdjustContentInsets": from_opt(automaticallyAdjustContentInsets),
            "contentInsets": from_opt(contentInsets),
            "injectJavaScript": from_opt(injectJavaScript),
            "injectedJavaScript": from_opt(injectedJavaScript),
            "mediaPlaybackRequiresUserAction": from_opt(mediaPlaybackRequiresUserAction),
            "onError": from_opt(onError),
            "onLoad": from_opt(onLoad),
            "onLoadEnd": from_opt(onLoadEnd),
            "onLoadStart": from_opt(onLoadStart),
            "onMessage": from_opt(onMessage),
            "onNavigationStateChange": from_opt(onNavigationStateChange),
            "renderError": from_opt(renderError),
            "renderLoading": from_opt(renderLoading),
            "scalesPageToFit": from_opt(scalesPageToFit),
            "startInLoadingState": from_opt(startInLoadingState),
            "domStorageEnabled": from_opt(domStorageEnabled),
            "javaScriptEnabled": from_opt(javaScriptEnabled),
            "mixedContentMode":
              from_opt(
                UtilsRN.option_map(
                  (contentMode) => {
                    let to_string =
                      fun
                      | `never => "never"
                      | `always => "always"
                      | `compatibility => "compatibility";
                    contentMode |> List.map(to_string) |> Array.of_list
                  },
                  mixedContentMode
                )
              ),
            "thirdPartyCookiesEnabled": from_opt(thirdPartyCookiesEnabled),
            "userAgent": from_opt(userAgent),
            "allowsInlineMediaPlayback": from_opt(allowsInlineMediaPlayback),
            "bounces": from_opt(bounces),
            "dataDetectorTypes":
              from_opt(
                UtilsRN.option_map(
                  (dataDetectorType) => {
                    let to_string =
                      fun
                      | `phoneNumber => "phoneNumber"
                      | `link => "link"
                      | `address => "address"
                      | `calendarEvent => "calendarEvent"
                      | `none => "none"
                      | `all => "all";
                    dataDetectorType |> List.map(to_string) |> Array.of_list
                  },
                  dataDetectorTypes
                )
              ),
            "decelerationRate":
              from_opt(
                UtilsRN.option_map(
                  (rate) => {
                    let to_float =
                      fun
                      | `normal => 0.998
                      | `fast => 0.99
                      | `value(f) => f;
                    rate |> List.map(to_float) |> Array.of_list
                  },
                  decelerationRate
                )
              ),
            "onShouldStartLoadWithRequest": from_opt(onShouldStartLoadWithRequest),
            "scrollEnabled": from_opt(scrollEnabled)
          }
        )
      )
  );
