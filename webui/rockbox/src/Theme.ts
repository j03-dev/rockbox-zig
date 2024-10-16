import { createLightTheme, createDarkTheme } from "baseui/themes";

export const BaseUIDarkTheme = createDarkTheme(
  {
    primaryFontFamily: "RockfordSansRegular",
  },
  {
    colors: {
      buttonPrimaryFill: "#fe099c",
      buttonPrimaryText: "#fff",
      buttonPrimaryHover: "#fe099cbe",
      buttonSecondaryFill: "rgba(171, 40, 252, 0.052)",
      buttonSecondaryText: "#fe099c",
      buttonSecondaryHover: "rgba(171, 40, 252, 0.107)",
      buttonTertiaryText: "#fff",
      buttonTertiaryFill: "#000",
      buttonTertiaryHover: "#0000009700044",
    },
  }
);

export const BaseUILightTheme = createLightTheme(
  {
    primaryFontFamily: "RockfordSansRegular",
  },
  {
    colors: {
      buttonPrimaryFill: "#fe099c",
      buttonPrimaryHover: "#fe099cbe",
      buttonSecondaryFill: "rgba(171, 40, 252, 0.052)",
      buttonSecondaryText: "#fe099c",
      buttonSecondaryHover: "rgba(171, 40, 252, 0.107)",
      buttonTertiaryText: "#fff",
      buttonTertiaryFill: "#000",
      buttonTertiaryHover: "#0000009700044",
    },
  }
);

export const LightTheme = {
  colors: {
    text: "#000",
    background: "#fff",
    icon: "#000",
    searchBackground: "rgba(247, 247, 247, 0.2)",
    searchBackgroundAlt: "rgba(255, 255, 255, 0.2)",
    secondaryBackground: "#fbf5ff",
    secondaryText: "rgba(0, 0, 0, 0.542)",
    backButton: "#f7f7f8",
    currentTrackBorder: "rgba(177, 178, 181, 0.25)",
    popoverBackground: "#fff",
    separator: "#e0e0e0cc",
    hover: "#b1b2b51a",
    cover: "#f3f3f3b9",
    tooltip: "#fe099c1a",
  },
};

export const DarkTheme = {
  colors: {
    text: "#fff",
    background: "#000",
    icon: "#828282",
    searchBackground: "#0f1010",
    searchBackgroundAlt: "#0f1010",
    secondaryBackground: "#281832",
    secondaryText: "#828282",
    backButton: "#242429",
    currentTrackBorder: "rgba(177, 178, 181, 0.15)",
    popoverBackground: "#141414",
    separator: "rgba(177, 178, 181, 0.15)",
    hover: "#242424",
    cover: "#2f2f2fb9",
    tooltip: "#fe099c38",
  },
};
