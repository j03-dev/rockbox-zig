import { render } from "@testing-library/react";
import Tracks from "./Tracks";
import Providers from "../../Providers";
import { tracks } from "./mocks";
import { MemoryRouter } from "react-router-dom";
import { MockedProvider } from "@apollo/client/testing";
import { mocks } from "../../mocks";

describe("Tracks", () => {
  it("should render", () => {
    const { container } = render(
      <MemoryRouter initialEntries={["/"]}>
        <MockedProvider mocks={mocks} addTypename={false}>
          <Providers>
            <Tracks tracks={tracks} />
          </Providers>
        </MockedProvider>
      </MemoryRouter>
    );
    expect(container).toMatchSnapshot();
  });
});
